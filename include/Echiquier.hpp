// Fichier : Echiquier.hpp
// Description : Fichier header pour la classe Echiquier. Classe pour gérer l'échiquier et les mouvements des pièces.
// Auteur : Amine Zerouali
// Date : 09/04/2023

#pragma once

#include "Piece.hpp"
#include <vector>
#include "Roi.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Fou.hpp"
#include "Dame.hpp"
#include "Pion.hpp"

namespace model {
    class Echiquier {
    public:
        Echiquier()=default;
        void ajouterPiece(const std::string& type, bool couleur, int x, int y);
        bool mouvementValide(int x1, int y1, int x2, int y2);
        bool estEnEchec(bool couleur);
        void initialiser();
        Piece* getPiece(int x, int y) const;
        bool movePiece(int x1, int y1, int x2, int y2);
        bool coordonneesValides(int x, int y) const;
        void changerTour() {
            tourBlancs = !tourBlancs; 
        }
        bool cheminLibre(int x1, int y1, int x2, int y2);
        void setPiece(int x, int y, Piece* piece) {
            echiquier[x][y] = piece;
        }
        int getNbPieces(std::string typePiece, bool couleur) const;


    private:
        std::vector<std::vector<Piece*>> echiquier;
        bool tourBlancs = true;
    };


    // question 3 TD6
    class Mouvement {
    public:
        Mouvement(Piece* piece, int x, int y) : piece_(piece), x_(x), y_(y) {}
        ~Mouvement() { echiquier_->setPiece(x_, y_, piece_); } // a la destruction la piece revient a sa position initial

    private:
        Piece* piece_;
        int x_;
        int y_;
        Echiquier* echiquier_ ;
    };

}