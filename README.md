# Fractol - Visualisation de Fractales en C

## Description
Fractol est un programme permettant de générer et d'explorer des fractales en utilisant la MiniLibX. Il permet d'afficher les ensembles de Julia et Mandelbrot avec des fonctionnalités interactives telles que le zoom et le changement de couleurs.

## Fonctionnalités
### Génération de Fractales
- Affichage des ensembles de **Julia** et **Mandelbrot**.
- Possibilité de générer différentes variantes de Julia en passant des paramètres.
- Gestion des couleurs pour donner un effet de profondeur aux fractales.

### Interaction Utilisateur
- **Zoom quasi-infini** avec la molette de la souris.
- **Navigation fluide** dans la fenêtre (réduction, changement de fenêtre, etc.).
- **Quitter le programme** proprement avec la touche `ESC` ou en cliquant sur la croix.

## Compilation et Exécution
### Compilation
Un `Makefile` est fourni pour compiler le projet sans relink :
```sh
make
```

### Exécution
```sh
./fractol <nom_de_fractale> [paramètres_optionnels pour Julia] <shift_color, entre 0 et 1>
```
Exemples :
```sh
./fractol mandelbrot 0.5
./fractol julia 0.285 0.01 1
```
Si un paramètre est invalide ou manquant, le programme affiche la liste des options disponibles.

## Gestion Graphique
- Affichage d'une image dans une fenêtre via la **MiniLibX**.
- Navigation fluide entre les fenêtres.
- Utilisation des images de la MiniLibX.

## Bonus
- **Ajout d'une fractale supplémentaire** : **Burning Ship**.
- **Zoom centré sur la position de la souris**.
- **Déplacement de la vue avec les flèches directionnelles**.
- **Effets de changement de couleurs dynamiques**.

## Screenshots
<img width="684" alt="Run" src="Imgs/Mandelbrot.png">
<img width="684" alt="Run" src="Imgs/Julia.png">
<img width="684" alt="Run" src="Imgs/Burning_Ship.png">

## Auteur
Projet développé par **[Aurelien Fontaine]**.

