Documentation du jeu - SFML
Introduction
Ce jeu utilise la bibliothèque SFML (Simple and Fast Multimedia Library) pour la gestion des graphismes, des événements clavier, et des objets dans le monde du jeu. Le joueur peut se déplacer dans l'environnement et interagir avec des objets (comme des potions) et des murs (comme des piliers). Ce document présente une vue d'ensemble de la logique du jeu, des classes principales utilisées et des instructions sur la manière de jouer.

Classes Principales
1. Player (Joueur)
La classe Player représente le personnage principal du jeu.

Fonctionnalités :
Déplacement : Le joueur peut se déplacer à l'aide des touches Q, Z, S, D. La vitesse est définie par la variable vitesse.
Boost de vitesse : Lorsque le joueur interagit avec une potion, il peut bénéficier d'un boost de vitesse temporaire pendant 4 secondes.
Gestion des collisions : Le joueur peut entrer en collision avec des objets comme des murs (définis par la classe Pillar). Lorsqu'une collision est détectée, le joueur s'arrête dans la direction de la collision.
Méthodes importantes :
speedboost() : Applique un boost de vitesse lorsque le joueur récupère une potion.
update() : Gère la mise à jour du joueur (déplacement et gestion de la collision) chaque frame.
checkCollision() : Vérifie si un mouvement donné (horizontal ou vertical) provoque une collision avec un mur.
2. Pillar (Pilier)
La classe Pillar représente un mur ou obstacle que le joueur ne peut pas traverser.

Fonctionnalités :
Collision avec le joueur : Si un joueur touche un pilier, il est empêché de continuer son mouvement dans la direction du pilier.
Affichage : Le pilier est affiché sur l'écran à partir d'une texture (chargée depuis un fichier image).
Méthodes importantes :
draw() : Dessine le pilier sur la fenêtre.
colisionplayer() : Vérifie si le joueur entre en collision avec le pilier et arrête son mouvement.
3. Potion (Potion)
La classe Potion représente un objet spécial que le joueur peut ramasser pour obtenir un boost de vitesse.

Fonctionnalités :
Interaction avec le joueur : Lorsque le joueur entre en collision avec la potion, cette dernière est "consommée" et le joueur bénéficie d'un boost de vitesse.
Affichage : La potion est affichée sur l'écran.
Méthodes importantes :
interact() : Gère l'interaction du joueur avec la potion (applique le boost de vitesse).
update() : Met à jour l'état de la potion (vérifie l'interaction avec le joueur et la dessine).
Système de Collision
Le système de collision dans ce jeu fonctionne en détectant les collisions entre le joueur et les piliers (obstacles). La classe Player vérifie si le joueur entre en collision avec un pilier avant d'appliquer un mouvement dans une direction donnée (haut, bas, gauche, droite). Si une collision est détectée, le mouvement dans la direction du pilier est annulé, empêchant ainsi le joueur de traverser les murs.

Le joueur peut également interagir avec les potions. Lorsqu'il entre en collision avec une potion, sa vitesse augmente pendant 4 secondes, ce qui lui permet de se déplacer plus rapidement.

Comment Jouer
Contrôles :
Déplacement du joueur :
Q : Déplace le joueur vers la gauche.
Z : Déplace le joueur vers le haut.
S : Déplace le joueur vers le bas.
D : Déplace le joueur vers la droite.
Boost de vitesse :
K : Active le boost de vitesse pour le joueur pendant 4 secondes (si le joueur est en contact avec une potion).
Quitter le jeu :
Échap : Ferme la fenêtre du jeu.
Objectifs du jeu :
Déplacez votre joueur dans le monde en évitant les obstacles (les piliers).
Interagissez avec des potions pour augmenter temporairement votre vitesse et éviter les collisions plus rapidement.
Le jeu se poursuit tant que vous n'avez pas quitté la fenêtre.
Interaction avec les objets :
Lorsque le joueur entre en collision avec une potion, il obtient un boost de vitesse temporaire. Les potions sont représentées par des objets graphiques et sont placées aléatoirement dans le monde du jeu. Chaque fois que le joueur touche une potion, il peut bénéficier de ce boost de vitesse.

Notes Techniques
Textures et ressources :

Le jeu utilise des images comme textures pour les objets (joueur, pilier, potion). Assurez-vous que les fichiers de textures sont présents dans les répertoires appropriés, sinon le jeu échouera à charger les images.
Gestion de la mémoire :

Les objets comme les Pillars et Potions sont créés dynamiquement avec new. Assurez-vous de les supprimer correctement lorsque le jeu termine, pour éviter les fuites de mémoire.
FPS et performance :

Le jeu est conçu pour tourner à 120 images par seconde (window.setFramerateLimit(120)) pour garantir une expérience fluide.
Conclusion
Ce projet présente un jeu simple où un joueur peut interagir avec des objets dans un environnement 2D. Le système de collision gère les interactions entre le joueur et les murs, ainsi que les boosts de vitesse obtenus en touchant des potions. Le jeu est construit sur SFML et permet de comprendre comment gérer les événements, les objets et les collisions dans un jeu vidéo basique.

Si tu as des questions ou souhaites ajouter de nouvelles fonctionnalités, n'hésite pas à modifier et étendre le code selon tes besoins.