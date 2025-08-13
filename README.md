
# Sujet :
Cub3D est un projet inspiré du jeu Wolfenstein 3D.
L’objectif est de créer un moteur 3D minimaliste en C en utilisant la technique du raycasting.
Il permet de se déplacer dans un labyrinthe en première personne, de détecter les collisions et d’afficher un environnement en pseudo-3D.

# Objectif :
- Parsing d'une map plus complète
- Gestion des collisions (mur)
- Comprendre le raycasting (projection 3D à partir d’un plan 2D).
- Apprendre à utiliser la MiniLibX pour l’affichage graphique.
- Gérer les événements clavier pour déplacer le joueur et tourner la caméra.
- Lire et interpréter une carte décrite dans un fichier .cub.

# Structure du projet :
1. Fichier .cub
Contient :
- Les chemins vers les textures des murs (NO, SO, WE, EA).
- La couleur du plafond et du sol (RGB).
- La carte en ASCII avec :

NO ./textures/no.xpm
SO ./textures/so.xpm
WE ./textures/we.xpm
EA ./textures/ea.xpm

F 101,67,33 → couleur sol
C 135,206,235 → couleur plafond

111111
100001
1000N1
111111

- 1 → mur
- 0 → espace vide
- N, S, E, W → position et orientation initiale du joueur

2. Parsing de la carte
- Charger les textures.
- Convertir les couleurs en format utilisable (0xRRGGBB).
- Stocker les données dans une structure.

3. Initialisation graphique
- Ouverture d’une fenêtre avec MiniLibX.
- Chargement des textures.
- Placement du joueur dans le monde.

4. Boucle de jeu
- Raycasting : pour chaque colonne de l’écran, envoyer un rayon et calculer la distance jusqu’au premier mur touché.
- Projection : convertir la distance en hauteur de mur à afficher.
- Rendu : afficher les murs avec la texture correspondante.

5. Contrôles
- Avancer / Reculer : W / S
- Tourner à gauche / droite : ← / →
- Strafe gauche / droite : A / D
- Quitter : ESC ou fermer la fenêtre

# Raycasting
Le raycasting est une technique utilisée pour simuler une vue 3D à partir d’un environnement 2D.
Plutôt que de modéliser tout un monde 3D, on envoie des rayons depuis la position du joueur vers la carte et on détecte où ils rencontrent un mur.
Cette méthode est rapide et idéale pour des jeux à la Wolfenstein 3D.

pixel_put :
Donne le pouvoir de tracer la moindre particule de ton monde
c'est la fondation ensuite -> ray-casting, textures, sprites, mini-map — se fait par-dessus ce mécanisme

DDA :
DDA (Digital Differential Analyzer) est l’algorithme de ray‐casting utilisé dans Cub3D pour détecter à partir de la position du joueur
où un rayon frappe un mur sur une carte en grille 2D.
Dès qu’on entre dans une case « mur », on sait où s’est produit l’impact

Draw_vertical :
Texture a afficher selon l'orientation du player
Coordonnee pour les bandes verticale a l'ecran
Defini la hauteur du mur
Draw_start et end permet de definir la texture du mur
Plus la dist est petite (proche), plus la hauteur du mur est grand
Tous part du centre (oeil du player), remonte la moitie de l'ecran ou descend pour dessiner le mur
Dessine plafond, mur, sol

# Compilation et exécution :
