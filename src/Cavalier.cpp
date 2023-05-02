// Fichier : Cavalier.cpp
// Description : Fichier source pour la classe Cavalier. Classe pour le cavalier, héritant de la classe Piece.
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#include "../include/Cavalier.hpp"

// Constructeur
Cavalier::Cavalier(bool couleur, int x, int y)
    : Piece("Cavalier", couleur, x, y) {
}


std::vector<std::pair<int, int>> Cavalier::mouvementsValides(int x, int y) const {
    std::vector<std::pair<int, int>> mouvements;

    // Les déplacements possibles en L pour le cavalier
    int deplacements[8][2] = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
    };

    for (int i = 0; i < 8; i++) {
        int newX = x + deplacements[i][0];
        int newY = y + deplacements[i][1];

        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            mouvements.push_back(std::make_pair(newX, newY));
        }
    }

    return mouvements;
} 
