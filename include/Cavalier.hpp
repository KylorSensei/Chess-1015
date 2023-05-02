// Fichier : Cavalier.hpp
// Description : Fichier header pour la classe Cavalier. Classe pour le cavalier, héritant de la classe Piece.
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#pragma once

#include "Piece.hpp"

class Cavalier : public Piece {
public:
    // Constructeur
    Cavalier( bool couleur, int x, int y);

    // Méthodes
    std::vector<std::pair<int, int>> Piece::mouvementsValides(int x, int y) const override;
    std::string getImagePath() const override {
        return getCouleur() ? "white_knight.png" : "black_knight.png";
    }

};
