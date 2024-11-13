# FDF
### Languages

- [French version](https://github.com/darambae/fdf/readme_fr.md)
- [Korean version](https://github.com/darambae/fdf/readme_kr.md)

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [3D Projection](#3d-projection)
- [Keyboard Controls](#keyboard-controls)
- [Mathematics and Formulas](#mathematics-and-formulas)
- [Languages](#languages)

---

### Introduction

**FDF** is a 3D wireframe renderer that converts 2D height maps into interactive 3D representations. Developed using the MiniLibX library, it allows users to explore and manipulate 3D landscapes in real-time.

### Features

- 3D projection of 2D height maps
- Height-based color gradients
- Zoom, translation, and rotation controls
- Adjustable projection type (isometric, parallel)

### Usage

To launch **FDF** with a map file:
```sh
./fdf path/to/map.fdf
```

You can test the program using example `.fdf` map files included in the `maps/` directory:
```sh
./fdf maps/42.fdf
```

### 3D Projection

**FDF** offers both isometric and parallel projection modes to create a visually engaging 3D effect from 2D maps:

- **Isometric Projection**: Projects points at a 45-degree angle to simulate depth, providing a classic 3D appearance.
- **Parallel Projection**: Projects without perspective, keeping all points equidistant for a more uniform look.

### Keyboard Controls

- **Arrow Keys**: Move the map view left, right, up, and down.
- **+ / -**: Zoom in and out.
- **W / A / S / D**: Rotate the map view.
- **I / P**: Toggle between isometric and parallel projection modes.
- **Esc**: Exit the program.

### Mathematics and Formulas

The **FDF** project relies on linear transformations to render 3D objects onto a 2D screen. Below are the core concepts and formulas applied.

#### 1. Isometric Projection

An isometric projection is used to represent three-dimensional objects in two dimensions while maintaining proportionality. It assumes a viewpoint where the x, y, and z axes are equally inclined to the viewing plane. 

For a given point `(x, y, z)` in 3D space, the isometric projection onto 2D screen coordinates `(X, Y)` is calculated using:
  
  ```
  X = (x - y) * cos(θ)
  Y = (x + y) * sin(θ) - z
  ```

  Where:
  - `θ` is typically 30 degrees for an isometric projection, but can vary.
  - `z` represents the height in the map file.

This formula allows **FDF** to create the illusion of depth by applying different x and y displacements and adjusting for the height with the z-axis value.

#### 2. Rotation

**Rotation** in 3D space around each axis is essential to create dynamic views of the wireframe model. The primary rotations are around the x, y, and z axes, using the following formulas:

- **Rotation around X-axis** (tilt up/down):
  ```
  y' = y * cos(angle) - z * sin(angle)
  z' = y * sin(angle) + z * cos(angle)
  ```

- **Rotation around Y-axis** (spin left/right):
  ```
  x' = x * cos(angle) + z * sin(angle)
  z' = -x * sin(angle) + z * cos(angle)
  ```

- **Rotation around Z-axis** (rotate flat):
  ```
  x' = x * cos(angle) - y * sin(angle)
  y' = x * sin(angle) + y * cos(angle)
  ```

  By adjusting the rotation angles dynamically, the program can provide an interactive experience where users can view the 3D map from various angles.

#### 3. Scaling

**Scaling** is applied to zoom in and out of the 3D object on the screen. This simply involves multiplying the x, y, and z coordinates by a scalar factor `s`:

  ```
  x' = x * s
  y' = y * s
  z' = z * s
  ```

This scaling factor `s` can be increased or decreased with user input, allowing zoom functionality.

#### 4. Translation

**Translation** shifts the entire projection on the screen without altering its shape or orientation. For instance, to move the object `dx` units horizontally and `dy` units vertically:

  ```
  x' = x + dx
  y' = y + dy
  ```

This provides control over the positioning of the 3D object, so users can center or reposition it on the screen as desired.


---
