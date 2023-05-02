// Fichier : Jeu.cpp
// Description : Fichier source pour la classe Jeu. Classe principale pour gérer le jeu et l'interface utilisateur.
// Auteur : Amine Zerouali
// Date : 09/04/2023
// Fichier: EchiquierScene.cpp


#include "Jeu.hpp"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>



gui::EchiquierScene::EchiquierScene(QObject* parent)
    : QGraphicsScene(parent) {
    echiquier.initialiser();
    updateScene();
}

//EchiquierScene::~EchiquierScene() {
//    for (auto item : itemsToDelete) {
//        delete item;
//    }
//}

//gui::AjouterPieceDialog::~AjouterPieceDialog() {
//    for (auto item : itemsToDelete) {
//        delete item;
//    }
//}

void gui::EchiquierScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    onMousePress(event);
}

void gui::EchiquierScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    onMouseRelease(event);
}

void gui::EchiquierScene::onMousePress(QGraphicsSceneMouseEvent* event) {
    QPointF point = event->scenePos();
    std::pair<int, int> coordonnees = sceneToEchiquierCoordinates(point);
    int x = coordonnees.second;
    int y = coordonnees.first;

    // Sélectionner une pièce
    Piece* piece = echiquier.getPiece(x, y);
    if (piece != nullptr) {
        piece->setSelected(true);
        updateScene();
    }
}

void gui::EchiquierScene::onMouseRelease(QGraphicsSceneMouseEvent* event) {
    QPointF point = event->scenePos();
    std::pair<int, int> coordonnees = sceneToEchiquierCoordinates(point);
    int x = coordonnees.second;
    int y = coordonnees.first;

    // Déplacer la pièce sélectionnée
    Piece* pieceSelectionnee = nullptr;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* piece = echiquier.getPiece(i, j);
            if (piece != nullptr && piece->isSelected()) {
                if (echiquier.movePiece(i, j, x, y)) {
                    updateScene();
                    pieceSelectionnee = piece;
                }
                piece->setSelected(false);
                updateScene();
                break;
            }
        }
    }
    if (pieceSelectionnee == nullptr) {
        QGraphicsRectItem* invalidMoveRect = new QGraphicsRectItem(y * 50, x * 50, 50, 50);
        QPen pen(Qt::red);
        pen.setWidth(2);
        invalidMoveRect->setPen(pen);
        addItem(invalidMoveRect);
        itemsToDelete.push_back(invalidMoveRect);
    }
}

void gui::EchiquierScene::updateScene() {
    clear();

    int caseSize = 50;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Dessiner les cases de l'échiquier
            QGraphicsRectItem* caseRect = new QGraphicsRectItem(i * caseSize, j * caseSize, caseSize, caseSize);
            if ((i + j) % 2 == 0) {
                caseRect->setBrush(QBrush(Qt::white));
            }
            else {
                caseRect->setBrush(QBrush(Qt::darkGray));
            }
            addItem(caseRect);
            itemsToDelete.push_back(caseRect);
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* piece = echiquier.getPiece(i, j);
            if (piece != nullptr) {
                QPixmap pixmap(QString::fromStdString(piece->getImagePath()));
                QGraphicsPixmapItem* item = new QGraphicsPixmapItem(pixmap.scaled(QSize(caseSize, caseSize), Qt::KeepAspectRatio));
                item->setPos(j * caseSize, i * caseSize);
                addItem(item);
                itemsToDelete.push_back(item);


                if (piece->isSelected()) {
                    QGraphicsRectItem* selectionRect = new QGraphicsRectItem(j * caseSize, i * caseSize, caseSize, caseSize);
                    QPen pen(Qt::yellow);
                    pen.setWidth(2);
                    selectionRect->setPen(pen);
                    addItem(selectionRect);
                    itemsToDelete.push_back(selectionRect);
                }
            }
        }
    }
}


std::pair<int, int> gui::EchiquierScene::sceneToEchiquierCoordinates(const QPointF& point) const {
    int x = static_cast<int>(point.x()) / 50;
    int y = static_cast<int>(point.y()) / 50;
    return std::make_pair(x, y);
}

void gui::EchiquierScene::contextMenuEvent(QGraphicsSceneContextMenuEvent* event) {
    QPointF point = event->scenePos();
    std::pair<int, int> coordonnees = sceneToEchiquierCoordinates(point);
    int x = coordonnees.second;
    int y = coordonnees.first;

    QMenu menu;
    QAction* addAction = menu.addAction("Ajouter une pièce");
    QAction* deleteAction = menu.addAction("Effacer la pièce");
    QAction* clearAction = menu.addAction("Clear l'échiquier"); 
    QAction* SetupAction = menu.addAction("Commencer une Partie");


    QAction* selectedItem = menu.exec(event->screenPos());
    if (selectedItem == addAction) {
        AjouterPieceDialog ajouterPieceDialog;
        if (ajouterPieceDialog.exec() == QDialog::Accepted) {
            QString typePiece = ajouterPieceDialog.getTypePiece();
            QString couleurPiece = ajouterPieceDialog.getCouleurPiece();
            if (typePiece != "Roi"){
                if (echiquier.getNbPieces("Roi", true) < 1 || echiquier.getNbPieces("Roi", false) < 1) {
                    QMessageBox message;
                    message.warning(nullptr, "Erreur", "Il faut poser un Roi de chaque couleur avant de pouvoir ajouter d'autres pièces !");
                    return;
                } 
            }
            //// Vérifier qu'il n'y a pas déjà un Roi de la même couleur sur l'échiquier (non demandé mais je vous conseille de decommenter car la logique n'est pas faite pour gerer 2 roi de meme couleur (mise en echec ...))
            //if (typePiece == "Roi") {
            //    bool couleur = (couleurPiece == "Blanc") ? true : false;
            //    if (echiquier.getNbPieces("Roi", couleur) >= 1) {
            //        QMessageBox message;
            //        QString messageText = (couleurPiece == "Blanc") ? "Il ne peut y avoir qu'un seul Roi blanc sur l'échiquier !" : "Il ne peut y avoir qu'un seul Roi noir sur l'échiquier !";
            //        message.warning(nullptr, "Erreur", messageText);
            //        return;
            //    }
            //}

            // Créer la pièce avec le type et la couleur sélectionnés
            bool couleur = (couleurPiece == "Blanc") ? true : false;
            try {
                echiquier.ajouterPiece(typePiece.toStdString(), couleur, x, y);
            }
            // question 2 TD6
            catch (const std::exception& e) {
                QMessageBox message;
                message.warning(nullptr, "Erreur", e.what());
                return;
            }

            updateScene();
        }
    }
    else if (selectedItem == clearAction) {
        // Clear l'échiquier
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                delete echiquier.getPiece(i, j);
                echiquier.setPiece(i, j, nullptr);

            }
        }
        updateScene();
    }
    else if (selectedItem == SetupAction) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                delete echiquier.getPiece(i, j);
                echiquier.setPiece(i, j, nullptr);
            }
        }
        //Ajouter les pièces pour les deux joueurs
        for (int i = 0; i < 8; i++) {
            echiquier.ajouterPiece("Pion", false, 1, i);
            echiquier.ajouterPiece("Pion", true, 6, i);
        }

        echiquier.ajouterPiece("Tour", false, 0, 0);
        echiquier.ajouterPiece("Tour", false, 0, 7);
        echiquier.ajouterPiece("Tour", true, 7, 0);
        echiquier.ajouterPiece("Tour", true, 7, 7);

        echiquier.ajouterPiece("Cavalier", false, 0, 1);
        echiquier.ajouterPiece("Cavalier", false, 0, 6);
        echiquier.ajouterPiece("Cavalier", true, 7, 1);
        echiquier.ajouterPiece("Cavalier", true, 7, 6);

        echiquier.ajouterPiece("Fou", false, 0, 2);
        echiquier.ajouterPiece("Fou", false, 0, 5);
        echiquier.ajouterPiece("Fou", true, 7, 2);
        echiquier.ajouterPiece("Fou", true, 7, 5);

        echiquier.ajouterPiece("Dame", false, 0, 3);
        echiquier.ajouterPiece("Dame", true, 7, 3);

        echiquier.ajouterPiece("Roi", false, 0, 4);
        echiquier.ajouterPiece("Roi", true, 7, 4);
        
        updateScene();
    }
    else if (selectedItem == deleteAction) {
        Piece* piece = echiquier.getPiece(x, y);
        if (piece != nullptr) {
            delete piece;
            echiquier.setPiece(x, y, nullptr);
            updateScene();
        }
    }
}


gui::AjouterPieceDialog::AjouterPieceDialog(QWidget* parent)
    : QDialog(parent) {
    setWindowTitle("Ajouter une pièce");
    setFixedSize(300, 150);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* typePieceLayout = new QHBoxLayout;
    QHBoxLayout* couleurPieceLayout = new QHBoxLayout;
    QHBoxLayout* boutonLayout = new QHBoxLayout;
    


    // Type de la pièce
    QLabel* typePieceLabel = new QLabel("Type :");
    typePieceComboBox = new QComboBox;
    typePieceComboBox->addItem("Pion");
    typePieceComboBox->addItem("Tour");
    typePieceComboBox->addItem("Cavalier");
    typePieceComboBox->addItem("Fou");
    typePieceComboBox->addItem("Dame");
    typePieceComboBox->addItem("Roi");
    typePieceLayout->addWidget(typePieceLabel);
    typePieceLayout->addWidget(typePieceComboBox);
    mainLayout->addLayout(typePieceLayout);

    // Couleur de la pièce
    QLabel* couleurPieceLabel = new QLabel("Couleur :");
    couleurPieceComboBox = new QComboBox;
    couleurPieceComboBox->addItem("Blanc");
    couleurPieceComboBox->addItem("Noir");
    couleurPieceLayout->addWidget(couleurPieceLabel);
    couleurPieceLayout->addWidget(couleurPieceComboBox);
    mainLayout->addLayout(couleurPieceLayout);

    // Boutons OK/Annuler
    QPushButton* okButton = new QPushButton("OK");
    QPushButton* annulerButton = new QPushButton("Annuler");
    boutonLayout->addWidget(okButton);
    boutonLayout->addWidget(annulerButton);
    mainLayout->addLayout(boutonLayout);

    setLayout(mainLayout);

    connect(okButton, &QPushButton::clicked, this, &AjouterPieceDialog::accept);
    connect(annulerButton, &QPushButton::clicked, this, &AjouterPieceDialog::reject);

    // Stocker les pointeurs alloués dynamiquement dans le vecteur itemsToDelete
    //itemsToDelete.push_back(mainLayout);
    //itemsToDelete.push_back(typePieceLayout);
    //itemsToDelete.push_back(couleurPieceLayout);
    //itemsToDelete.push_back(boutonLayout);
    //itemsToDelete.push_back(typePieceComboBox); 
    //itemsToDelete.push_back(couleurPieceComboBox); 
    //itemsToDelete.push_back(okButton);
    //itemsToDelete.push_back(annulerButton);

}

QString gui::AjouterPieceDialog::getTypePiece() const {
    return typePieceComboBox->currentText();
}

QString gui::AjouterPieceDialog::getCouleurPiece() const {
    return couleurPieceComboBox->currentText();
}

