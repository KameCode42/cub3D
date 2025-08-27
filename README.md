<img width="720" height="720" alt="Image" src="https://github.com/user-attachments/assets/459b0615-9cab-49eb-9d78-39ee16922e7d" />

# Sujet :
Cub3D est un projet inspiré du jeu Wolfenstein 3D. <br>
L’objectif est de créer un moteur 3D minimaliste en C en utilisant la technique du raycasting. <br>
Il permet de se déplacer dans un labyrinthe en première personne, de détecter les collisions et d’afficher un environnement en pseudo-3D. <br>

# Objectif du projet :
- Comprendre le raycasting (projection 3D à partir d’un plan 2D).
- Apprendre à utiliser la MiniLibX pour l’affichage graphique.
- Gérer les événements clavier pour déplacer le joueur et tourner la caméra.
- Lire et interpréter une carte décrite dans un fichier .cub.

# Structure du projet :
1️. Fichier .cub
- Les chemins vers les textures des murs (NO, SO, WE, EA).
- La couleur du plafond et du sol (RGB).
- La carte en ASCII :
- 1 → mur
- 0 → espace vide
- N, S, E, W → position et orientation initiale du joueur

Exemple de carte :
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111 <br>
100001 <br>
1000N1 <br>
111111 <br>
