// Fichier : Piece.cpp
// Description : Fichier source pour la classe Piece. Classe de base pour toutes les pièces d'échecs.
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#include "../include/Piece.hpp"

// Constructeur
Piece::Piece(const std::string& nom, bool couleur, int x, int y)
    : nom_(nom), couleur_(couleur), selected_(false) {
    position_.x = x;
    position_.y = y;
}


// Getters et setters
std::string Piece::getNom() const {
    return nom_;
}

bool Piece::isSelected() const {
    return selected_;
}

void Piece::setSelected(bool selected) {
    selected_ = selected;
}

bool Piece::getCouleur() const {
    return couleur_;
}

Position Piece::getPosition() const {
    return position_;
}

void Piece::setPosition(const Position& position) {
    position_ = position;
}
