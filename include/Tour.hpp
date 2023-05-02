// Fichier : Tour.hpp
// Description : Fichier header pour la classe Tour. Classe pour la tour, héritant de la classe Piece.
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#pragma once

#include "Piece.hpp"

class Tour : public Piece {
public:
    // Constructeur
    Tour(bool couleur, int x, int y);

    // Méthode pour obtenir les mouvements valides de la tour
    std::vector<std::pair<int, int>> mouvementsValides(int x, int y) const override;
    std::string getImagePath() const override {
        return getCouleur() ? "white_rook.png" : "black_rook.png";
    }
};
