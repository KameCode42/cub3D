# Minimap

Ce module ajoute une mini-carte en haut à gauche de la fenêtre du jeu pour visualiser la carte 2D et la position du joueur.

## Fonctionnalités

- Affiche une représentation 2D de la carte
- Montre la position actuelle du joueur
- Indique la direction dans laquelle regarde le joueur
- S'actualise en temps réel avec les mouvements du joueur

## Configuration

Les paramètres de la mini-carte peuvent être modifiés en ajustant les constantes définies en haut du fichier `minimap.c` :

- `MINIMAP_SIZE` : Taille de la mini-carte en pixels
- `CELL_SIZE` : Taille de chaque cellule sur la mini-carte
- `WALL_COLOR` : Couleur des murs
- `FLOOR_COLOR` : Couleur du sol
- `PLAYER_COLOR` : Couleur du joueur
- `MINIMAP_BORDER` : Épaisseur de la bordure
- `BORDER_COLOR` : Couleur de la bordure
- `PLAYER_SIZE` : Taille du point représentant le joueur
- `DIR_LINE_LENGTH` : Longueur de la ligne indiquant la direction

## Utilisation

La mini-carte est automatiquement dessinée à chaque frame. Aucune action supplémentaire n'est requise pour l'utiliser.

## Extension possible

1. Ajouter une fonctionnalité de zoom pour la mini-carte
2. Permettre de la déplacer ou de la masquer avec une touche
3. Ajouter des éléments spéciaux (objets, ennemis, etc.)
