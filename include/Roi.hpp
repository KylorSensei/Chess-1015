// Fichier : Roi.hpp
// Description : Classe Roi, héritant de la classe Piece
// Représente le roi dans un jeu d'échecs et gère ses mouvements valides
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#pragma once


#include "Piece.hpp" // Inclusion de la classe de base Piece
#include <stdexcept> 


class Roi : public Piece {
public:
    // Constructeur
    Roi(bool couleur, int x, int y);
    ~Roi();

    // Méthode pour obtenir les mouvements valides de la dame
    std::vector<std::pair<int, int>> mouvementsValides(int x, int y) const override;
    std::string getImagePath() const override {
        return getCouleur() ? "white_king.png" : "black_king.png";
    }
    static int compteur; // variable de classe pour compter le nombre d'instances de la classe Roi
};


