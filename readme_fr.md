
### French Version: [README_fr.md](#)

# FDF

## Table des matières

- [Introduction](#introduction)
- [Fonctionnalités](#fonctionnalités)
- [Utilisation](#utilisation)
- [Projection 3D](#projection-3d)
- [Contrôles Clavier](#contrôles-clavier)
- [Mathématiques et Formules](#mathématiques-et-formules)
- [Langues](#langues)

---

### Introduction

**FDF** est un rendu de fil de fer 3D qui convertit des cartes de hauteur 2D en représentations 3D interactives. Développé avec la bibliothèque MiniLibX, il permet aux utilisateurs d'explorer et de manipuler des paysages 3D en temps réel.

### Fonctionnalités

- Projection 3D de cartes de hauteur 2D
- Gradients de couleur basés sur la hauteur
- Contrôles de zoom, de translation et de rotation
- Mode de projection ajustable (isométrique, parallèle)

### Utilisation

Pour lancer **FDF** avec un fichier de carte :
```sh
./fdf chemin/vers/carte.fdf
```

Vous pouvez tester le programme avec des fichiers de carte `.fdf` dans le répertoire `maps/` :
```sh
./fdf maps/42.fdf
```

### Projection 3D

**FDF** propose des modes de projection isométrique et parallèle pour créer un effet 3D visuellement attractif à partir de cartes 2D :

- **Projection isométrique** : Projette les points à un angle de 45 degrés pour simuler la profondeur, offrant un rendu classique en 3D.
- **Projection parallèle** : Projette sans perspective, gardant tous les points équidistants pour un aspect plus uniforme.

### Contrôles Clavier

- **Flèches** : Déplacer la vue de la carte à gauche, à droite, en haut et en bas.
- **+ / -** : Zoom avant et arrière.
- **W / A / S / D** : Faire pivoter la vue de la carte.
- **I / P** : Basculer entre les modes de projection isométrique et parallèle.
- **Échap** : Quitter le programme.

### Mathématiques et Formules

Le projet **FDF** repose sur des transformations linéaires pour afficher des objets 3D sur un écran 2D. Voici les concepts de base et les formules appliquées.

#### 1. Projection isométrique

La projection isométrique est utilisée pour représenter des objets tridimensionnels en deux dimensions tout en conservant la proportionnalité. Elle suppose un point de vue où les axes x, y et z sont également inclinés par rapport au plan de vue. 

Pour un point donné `(x, y, z)` en 3D, la projection isométrique en coordonnées 2D `(X, Y)` se calcule ainsi :
  
  ```
  X = (x - y) * cos(θ)
  Y = (x + y) * sin(θ) - z
  ```

  Où :
  - `θ` est généralement de 30 degrés pour une projection isométrique, mais peut varier.
  - `z` représente la hauteur dans le fichier de carte.

Cette formule permet à **FDF** de créer l'illusion de profondeur en appliquant des décalages x et y différents et en ajustant la hauteur avec la valeur de l'axe z.

#### 2. Rotation

La **rotation** en 3D autour de chaque axe est essentielle pour créer des vues dynamiques du modèle en fil de fer. Les rotations principales sont autour des axes x, y et z, avec les formules suivantes :

- **Rotation autour de l'axe X** (inclinaison haut/bas) :
  ```
  y' = y * cos(angle) - z * sin(angle)
  z' = y * sin(angle) + z * cos(angle)
  ```

- **Rotation autour de l'axe Y** (tourner gauche/droite) :
  ```
  x' = x * cos(angle) + z * sin(angle)
  z' = -x * sin(angle) + z * cos(angle)
  ```

- **Rotation autour de l'axe Z** (rotation plate) :
  ```
  x' = x * cos(angle) - y * sin(angle)
  y' = x * sin(angle) + y * cos(angle)
  ```

En ajustant dynamiquement les angles de rotation, le programme permet une expérience interactive où les utilisateurs peuvent voir la carte 3D sous différents angles.

#### 3. Mise à l'échelle

**La mise à l'échelle** est appliquée pour zoomer ou dézoomer sur l'objet 3D à l'écran. Elle consiste simplement à multiplier les coordonnées x, y et z par un facteur de mise à l'échelle `s` :

  ```
  x' = x * s
  y' = y * s
  z' = z * s
  ```

Ce facteur d'échelle `s` peut être augmenté ou diminué selon l'entrée de l'utilisateur, permettant ainsi la fonction de zoom.

#### 4. Translation

La **translation** déplace la projection entière sur l'écran sans altérer sa forme ni son orientation. Par exemple, pour déplacer l'objet de `dx` unités horizontalement et de `dy` unités verticalement :

  ```
  x' = x + dx
  y' = y + dy
  ```

Cela permet de contrôler la position de l'objet 3D pour que les utilisateurs puissent le centrer ou le repositionner sur l'écran comme souhaité.

### Langues

Cette README est également disponible en :
- [Version anglaise](https://github.com/your-username/fdf/readme.md)
- [Version coréenne](https://github.com/your-username/fdf/readme_kr.md)

---

