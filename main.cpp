// Fichier : main.cpp
// Description : Fichier principal pour lancer le jeu et l'interface utilisateur.
// Auteur : Amine Zerouali
// Date : 09/04/2023


#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QFont>
#include "Jeu.hpp"

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char *argv[]) 
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	//QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);

    QApplication app(argc, argv);

    // Créez et configurez le QGraphicsView
    QGraphicsView view;
    view.setRenderHint(QPainter::Antialiasing);
    view.setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing, true);
    view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setFixedSize(400, 400);

    // Créez et configurez le QGraphicsScene
    gui::EchiquierScene scene;
    scene.setSceneRect(0, 0, 400, 400);
    view.setScene(&scene);

    // Dessinez l'échiquier 
    int caseSize = 50;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            QGraphicsRectItem* rect = new QGraphicsRectItem(y * caseSize, x * caseSize, caseSize, caseSize);
            rect->setBrush(((x + y) % 2 == 0) ? Qt::white : Qt::darkGray);
            scene.addItem(rect);
        }
    }

    // Créez et positionnez les pièces d'échecs
    model::Echiquier echiquier; 
    echiquier.initialiser(); 

    // Affichez les pièces d'échecs sur l'échiquier
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            Piece* piece = echiquier.getPiece(x, y);
            if (piece != nullptr) {
                QPixmap pixmap(QString::fromStdString(piece->getImagePath()));
                QGraphicsPixmapItem* item = new QGraphicsPixmapItem(pixmap.scaled(QSize(caseSize, caseSize), Qt::KeepAspectRatio));
                item->setPos(y * caseSize, x * caseSize);
                scene.addItem(item);
            }
        }
    }

    //QPushButton* ajouterPieceButton = new QPushButton("Ajouter une pièce");
    //QObject::connect(ajouterPieceButton, &QPushButton::clicked, [&]() {
    //    // Code pour ouvrir la nouvelle fenêtre ici
    //    });


    // Affichez la fenêtre
    view.show();
    return app.exec();
}

