// Fichier : Fou.hpp
// Description : Fichier header pour la classe Fou. Classe pour le fou, héritant de la classe Piece.
// Auteur : Amine Zerouali
// Date : 09/04/2023

#pragma once

#include "Piece.hpp"

class Fou : public Piece {
public:
    // Constructeur
    Fou(bool couleur, int x, int y);

    // Méthode pour obtenir les mouvements valides du fou
    std::vector<std::pair<int, int>> Piece::mouvementsValides(int x, int y) const override;
    std::string getImagePath() const override {
        return getCouleur() ? "white_bishop.png" : "black_bishop.png";
    }
};