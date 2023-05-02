// Fichier : Tour.cpp
// Description : Fichier source pour la classe Tour. Classe pour la tour, héritant de la classe Piece.
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#include "../include/Tour.hpp" // Inclusion de la déclaration de la classe Tour

// Constructeur
Tour::Tour(bool couleur, int x, int y)
    : Piece("Tour", couleur, x, y) {
}

// Méthode pour obtenir les mouvements valides de la tour
std::vector<std::pair<int, int>> Tour::mouvementsValides(int x, int y) const {
    std::vector<std::pair<int, int>> mouvements;

    // Les déplacements possibles sur les lignes et rangées pour la tour
    int directions[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
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
