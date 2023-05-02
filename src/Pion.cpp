// Fichier : Pion.cpp
// Description : Fichier source pour la classe Pion. Classe pour le pion, héritant de la classe Piece.
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#include "../include/Pion.hpp"
//#include "Echiquier.hpp"
//
//Echiquier echiquier;

// Constructeur
Pion::Pion(bool couleur, int x, int y)
    : Piece("Pion", couleur, x, y) {
}

// Méthode pour obtenir les mouvements valides du pion
std::vector<std::pair<int, int>> Pion::mouvementsValides(int x, int y) const {
    std::vector<std::pair<int, int>> mouvements;

    int direction = getCouleur() ? -1 : 1;

    // Déplacement d'une case vers l'avant
    int newX = x + direction;
    int newY = y;
    if (newX >= 0 && newX < 8) {
        mouvements.push_back(std::make_pair(newX, newY));
    }

    // Déplacement de deux cases vers l'avant depuis la position initiale
    if ((getCouleur() && x == 6) || (!getCouleur() && x == 1)) {
        newX = x + 2 * direction;
        if (newX >= 0 && newX < 8) {
            mouvements.push_back(std::make_pair(newX, newY));
        }
    }

    // Prise en diagonale
    for (int dy = -1; dy <= 1; dy += 2) {
        newX = x + direction;
        newY = y + dy;
        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            //// Vérifier si la case diagonale est occupée par une pièce adverse
            //Piece* piece = echiquier.getPiece(newX, newY);
            //if (piece && piece->getCouleur() != getCouleur()) {
                mouvements.push_back(std::make_pair(newX, newY));
            /*}*/
        }
    }

    return mouvements;
}
