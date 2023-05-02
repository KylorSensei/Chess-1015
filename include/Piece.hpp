// Fichier : Piece.hpp
// Description : Fichier d'en-tête pour la classe Piece. Classe de base pour toutes les pièces d'échecs.
// Auteur : Amine Zerouali et Amine Ghabia
// Date : 09/04/2023

#pragma once

#include <string>
#include <vector>
#include <utility>



struct Position {
    int x;
    int y;
};

class Piece {
public:
    // Constructeur
    Piece(const std::string& nom, bool couleur, int x, int y);
    
    // Destructeur virtuel
    virtual ~Piece() {}

    // Méthodes
    virtual std::vector<std::pair<int, int>> mouvementsValides(int x, int y) const = 0;
    virtual std::string getImagePath() const = 0;
    bool isSelected() const;
    void setSelected(bool selected);

    // Getters et setters
    std::string getNom() const;
    bool getCouleur() const;
    Position getPosition() const;
    void setPosition(const Position& position);

private:
    std::string nom_;
    bool couleur_; // true pour blanc, false pour noir
    Position position_;
    bool selected_;
};
