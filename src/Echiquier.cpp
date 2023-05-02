// Fichier : Echiquier.cpp
// Description : Fichier source pour la classe Echiquier. Classe pour gérer l'échiquier et les mouvements des pièces.
// Auteur : Amine Zerouali
// Date : 09/04/2023

#include "../include/Echiquier.hpp"


void model::Echiquier::ajouterPiece(const std::string& type, bool couleur, int x, int y) { 
    if (type == "Roi") { 
        echiquier[x][y] = new Roi(couleur, x, y);   
    }
    else if (type == "Tour") {
        echiquier[x][y] = new Tour(couleur, x, y);
    }
    else if (type == "Cavalier") {
        echiquier[x][y] = new Cavalier(couleur, x, y);
    }
    else if (type == "Fou") {
        echiquier[x][y] = new Fou(couleur, x, y);
    }
    else if (type == "Dame") {
        echiquier[x][y] = new Dame(couleur, x, y);
    }
    else if (type == "Pion") {
        echiquier[x][y] = new Pion(couleur, x, y);
    }

    // question 2 TD6

    if (type == "Roi") {
        Roi::compteur++;
        if (Roi::compteur > 2) {
            Roi::compteur--;
            delete echiquier[x][y];
            echiquier[x][y] = nullptr;
            throw std::runtime_error("Il ne peut y avoir que deux rois sur l'échiquier !");
        }
    }
}

bool model::Echiquier::coordonneesValides(int x, int y) const {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

Piece* model::Echiquier::getPiece(int x, int y) const {
    if (coordonneesValides(x, y)) {
        return echiquier[x][y];
    }
    return nullptr;
}

void model::Echiquier::initialiser() {
    // Initialiser l'échiquier avec des pointeurs nuls
    echiquier.resize(8, std::vector<Piece*>(8, nullptr));

    //ajouterPiece("Roi", false, 0, 3);
    /*ajouterPiece("Roi", true, 7, 3);*/

    ajouterPiece("Cavalier", false, 0, 6); 
    ajouterPiece("Cavalier", true, 7, 1);

    ajouterPiece("Tour", false, 0, 7);
    ajouterPiece("Tour", true, 7, 0);
}

int model::Echiquier::getNbPieces(std::string typePiece, bool couleur) const {
    int nbPieces = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* piece = echiquier[i][j];
            if (piece != nullptr && piece->getCouleur() == couleur && piece->getNom() == typePiece) {
                nbPieces++;
            }
        }
    }
    return nbPieces;
}

bool model::Echiquier::cheminLibre(int x1, int y1, int x2, int y2) {
    // Vérifier les mouvements verticaux
    if (x1 == x2) {
        int minY = std::min(y1, y2);
        int maxY = std::max(y1, y2);
        for (int y = minY + 1; y < maxY; y++) {
            if (echiquier[x1][y] != nullptr) {
                return false;
            }
        }
    }
    // Vérifier les mouvements horizontaux
    else if (y1 == y2) {
        int minX = std::min(x1, x2);
        int maxX = std::max(x1, x2);
        for (int x = minX + 1; x < maxX; x++) {
            if (echiquier[x][y1] != nullptr) {
                return false;
            }
        }
    }
    // Vérifier les mouvements diagonaux
    else if (abs(x2 - x1) == abs(y2 - y1)) {
        int minX = std::min(x1, x2);
        int minY = std::min(y1, y2);
        int maxX = std::max(x1, x2);
        int maxY = std::max(y1, y2);
        int x = minX + 1;
        int y = minY + 1;
        while (x < maxX && y < maxY) {
            if (echiquier[x][y] != nullptr) {
                return false;
            }
            x++;
            y++;
        }
    }
    else {
        // Mouvement invalide (ni vertical, ni horizontal, ni diagonal)
        return false;
    }
    return true;
}

bool model::Echiquier::estEnEchec(bool couleur) {
    // Trouver la position du roi
    int roiX, roiY;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            Piece* piece = getPiece(x, y);
            if (piece != nullptr && piece->getNom() == "Roi" && piece->getCouleur() == couleur) {
                roiX = x;
                roiY = y;
            }
        }
    }

    // Vérifier si une pièce adverse peut atteindre la position du roi
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            Piece* piece = getPiece(x, y);
            if (piece != nullptr && piece->getCouleur() != couleur) {
                std::vector<std::pair<int, int>> mouvements = piece->mouvementsValides(x, y);
                for (const auto& mouvement : mouvements) {
                    if (mouvement.first == roiX && mouvement.second == roiY) {
                        // Vérifier si le chemin entre la pièce et le roi est libre
                        if (cheminLibre(x, y, roiX, roiY)) {
                            return true; // Le roi est en échec
                        }
                    }
                }
            }
        }
    }

    return false; // Le roi n'est pas en échec
}


bool model::Echiquier::mouvementValide(int x1, int y1, int x2, int y2) {
    Piece* piece = echiquier[x1][y1];
    if (piece == nullptr) {
        return false; // Pas de pièce à déplacer
    }

    Piece* pieceCapturee = echiquier[x2][y2];

    // Vérifier si le mouvement est valide pour la pièce
    std::vector<std::pair<int, int>> mouvements = piece->mouvementsValides(x1, y1);
    bool mouvementValide = false;
    for (const auto& mouvement : mouvements) {
        if (mouvement.first == x2 && mouvement.second == y2) {
            if (piece->getNom() == "Pion" && abs(y2 - y1) == 1 && pieceCapturee == nullptr) {
                mouvementValide = false;
                break;
            }
            if (piece->getNom() == "Pion" && ((abs(x2 - x1) == 1 && abs(y2 - y1) == 0) || (abs(x2 - x1) == 2 && abs(y2 - y1) == 0)) && pieceCapturee != nullptr) {
                mouvementValide = false;
                break;
            }
            if (piece->getNom() == "Tour" || piece->getNom() == "Fou" || piece->getNom() == "Pion" || piece->getNom() == "Dame") {
                // Vérifier si le chemin est libre pour les pièces concernées
                if (!cheminLibre(x1, y1, x2, y2)) {
                    mouvementValide = false;
                    break;
                }
            }
            mouvementValide = true;
            break;
        }
    }

    if (!mouvementValide) {
        return false; // Le mouvement n'est pas valide pour cette pièce
    }

    // Vérifier si la pièce de destination est de la même couleur
    if (pieceCapturee != nullptr && pieceCapturee->getCouleur() == piece->getCouleur()) {
        return false; // Ne pas capturer ses propres pièces
    }

    // Simuler le mouvement et vérifier si cela met le roi en échec
    
    echiquier[x2][y2] = piece;
    echiquier[x1][y1] = nullptr;
    bool roiEnEchec = estEnEchec(piece->getCouleur());
    echiquier[x1][y1] = piece;
    if (!roiEnEchec) {
        // Si le mouvement est valide, capturer la pièce adverse si elle est présente
        if (pieceCapturee != nullptr && pieceCapturee->getCouleur() != piece->getCouleur()) {
            delete pieceCapturee;
        }
        echiquier[x2][y2] = piece;
    }
    else {
        echiquier[x2][y2] = pieceCapturee; // Restaurer la pièce capturée si le mouvement n'est pas valide
    }

    return !roiEnEchec; // Le mouvement est valide si le roi n'est pas en échec
}


bool model::Echiquier::movePiece(int x1, int y1, int x2, int y2) {
    Piece* piece = echiquier[x1][y1];

    // Vérifiez si c'est le bon tour pour cette couleur
    if ((piece->getCouleur() && !tourBlancs) || (!piece->getCouleur() && tourBlancs)) {
        return false;
    }

    if (mouvementValide(x1, y1, x2, y2)) {
        Piece* pieceCapturee = echiquier[x2][y2];

        // Si le mouvement est valide, capturer la pièce adverse si elle est présente
        if (pieceCapturee != nullptr && pieceCapturee->getCouleur() != piece->getCouleur()) {
            delete pieceCapturee;
        }
        echiquier[x2][y2] = piece;
        echiquier[x1][y1] = nullptr;

        changerTour(); // Changez de tour après avoir effectué un mouvement valide
        return true;
    }
    return false;
}


