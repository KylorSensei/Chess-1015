// Fichier : Jeu.hpp
// Description : Fichier header pour la classe Jeu. Classe principale pour gérer le jeu et l'interface utilisateur.
// Auteur : Amine Zerouali
// Date : 09/04/2023
//
// Fichier: EchiquierScene.hpp
#pragma once

#include <QGraphicsScene>
#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include "Echiquier.hpp"
#include <vector>

namespace gui {
    class EchiquierScene : public QGraphicsScene {
        Q_OBJECT

    public:
        EchiquierScene(QObject* parent = nullptr);
        //virtual ~EchiquierScene();

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
        void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;


    private slots:
        void onMousePress(QGraphicsSceneMouseEvent* event);
        void onMouseRelease(QGraphicsSceneMouseEvent* event);

    private:
        void updateScene();
        std::pair<int, int> sceneToEchiquierCoordinates(const QPointF& point) const;
        model::Echiquier echiquier;
        std::vector<QGraphicsItem*> itemsToDelete;
    };




    class AjouterPieceDialog : public QDialog {
        Q_OBJECT

    public:
        AjouterPieceDialog(QWidget* parent = nullptr);
        //~AjouterPieceDialog();
        QString getTypePiece() const;
        QString getCouleurPiece() const;


    //private slots:
    //    void onTypePieceChanged(int index);
    //    void onCouleurPieceChanged(int index);
    //    void onAjouterPieceClicked();
    

    private:
        QComboBox* typePieceComboBox;
        QComboBox* couleurPieceComboBox;
        QPushButton* ajouterPieceButton;
        //QVector<QObject*> itemsToDelete;

    };
}