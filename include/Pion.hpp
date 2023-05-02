// Fichier : Pion.hpp
// Description : Fichier header pour la classe Pion. Classe pour le pion, héritant de la classe Piece.
// Auteur : Amine Zerouali
// Date : 09/04/2023

#pragma once

#include "Piece.hpp"

class Pion : public Piece {
public:
    // Constructeur
    Pion(bool couleur, int x, int y);

    // Méthode pour obtenir les mouvements valides du pion
    std::vector<std::pair<int, int>> mouvementsValides(int x, int y) const override;
    std::string getImagePath() const override {
        return getCouleur() ? "white_pawn.png" : "black_pawn.png";
    }

};
