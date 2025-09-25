# GamutShell structure

## Description

Contains information that defines a gamut shell, which is represented by a list of indexed triangles. The vertex buffer contains the vertices data.

## Members

### `JMin`

The minimum lightness of the shell.

### `JMax`

The maximum lightness of the shell.

### `cVertices`

The number of vertices in the shell.

### `cTriangles`

The number of triangles in the shell.

### `pVertices`

### `pTriangles`

#### - *pTriangles

A pointer to the indexed triangles.

#### - *pVertices

A pointer to the vertices data.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Structures](https://learn.microsoft.com/windows/win32/wcs/structures)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)