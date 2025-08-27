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

Exemple de carte : <br>

NO ./textures/north.xpm <br>
SO ./textures/south.xpm <br>
WE ./textures/west.xpm <br>
EA ./textures/east.xpm <br>
F 220,100,0 <br>
C 225,30,0 <br>

111111 <br>
100001 <br>
1000N1 <br>
111111 <br>

- 1 → mur
- 0 → espace vide
- N, S, E, W → position et orientation initiale du joueur

2️. Parsing de la carte
- Vérifier que la carte est fermée (pas de trous).
- Charger les textures.
- Convertir les couleurs en format utilisable (0xRRGGBB).
- Stocker les données dans une structure.

3️. Initialisation graphique
- Ouverture d’une fenêtre avec MiniLibX.
- Chargement des textures.
- Placement du joueur dans le monde.

4️. Boucle de jeu
- Raycasting : pour chaque colonne de l’écran, envoyer un rayon et calculer la distance jusqu’au premier mur touché.
- Projection : convertir la distance en hauteur de mur à afficher.
- Rendu : afficher les murs avec la texture correspondante.

5️. Contrôles
- Avancer / Reculer : W / S
- Tourner à gauche / droite : ← / →
- Strafe gauche / droite : A / D
- Quitter : ESC ou fermer la fenêtre

# Concepts clés :
Raycasting
- Simule un champ de vision.
- Chaque rayon calcule la première collision avec un mur.
- La hauteur du mur affiché dépend de la distance du rayon.







