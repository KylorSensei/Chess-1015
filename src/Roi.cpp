// Fichier : Roi.cpp
// Description : Fichier source pour la classe Roi. Classe pour le roi, héritant de la classe Piece.
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#include "../include/Roi.hpp"

int Roi::compteur = 0; // initialisation de la variable de classe

// Constructeur
Roi::Roi(bool couleur, int x, int y)
    : Piece("Roi", couleur, x, y) {
    //if (compteur >= 2) { // si le nombre d'instances est déjà de 2 ou plus, lancer une exception
    //    throw std::runtime_error("Erreur : il ne peut y avoir que deux rois sur l'échiquier !");
    //}
    //compteur++; // augmenter le nombre d'instances
}
Roi::~Roi() {
    compteur--;
}

// Méthode pour obtenir les mouvements valides du roi
std::vector<std::pair<int, int>> Roi::mouvementsValides(int x, int y) const {
    std::vector<std::pair<int, int>> mouvements;

    // Les déplacements possibles pour le roi
    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
    };

    for (int i = 0; i < 8; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // Vérifiez si le mouvement est dans les limites de l'échiquier
        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            mouvements.push_back(std::make_pair(newX, newY));
        }
    }

    // Les mouvements de roque ne sont pas inclus dans cette méthode car ils dépendent de l'état global de l'échiquier.
    // Il faudra les gérer dans une classe supérieure qui gère l'état du jeu et les règles spéciales comme le roque.

    return mouvements;
}
