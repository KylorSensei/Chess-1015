// Fichier : Fou.cpp
// Description : Fichier source pour la classe Fou. Classe pour le fou, héritant de la classe Piece.
// Auteur : Amine Zerouali
// Date : 09/04/2023

#include "../include/Fou.hpp"


// Constructeur
Fou::Fou(bool couleur, int x, int y)
    : Piece("Fou", couleur, x, y) {
}

// Méthode pour obtenir les mouvements valides du fou
std::vector<std::pair<int, int>> Fou::mouvementsValides(int x, int y) const {
    std::vector<std::pair<int, int>> mouvements;

    // Les déplacements possibles sur les diagonales pour le fou
    int directions[4][2] = {
        {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
    };

    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // Continuez à se déplacer dans une direction jusqu'à atteindre les bords de l'échiquier ou une autre pièce
        while (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            mouvements.push_back(std::make_pair(newX, newY));

            // Mettre à jour les coordonnées pour le prochain déplacement dans la même direction
            newX += directions[i][0];
            newY += directions[i][1];
        }
    }

    return mouvements;
}