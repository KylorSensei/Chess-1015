// Fichier : Dame.hpp
// Description : Fichier header pour la classe Dame. Classe pour la dame, héritant de la classe Piece.
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#pragma once

#include "Piece.hpp"

class Dame : public Piece { 
public:
    // Constructeur
    Dame(bool couleur, int x, int y);

    // Méthode pour obtenir les mouvements valides de la dame
    std::vector<std::pair<int, int>> mouvementsValides(int x, int y) const override;
    std::string getImagePath() const override {
        return getCouleur() ? "white_queen.png" : "black_queen.png";
    }
};
 