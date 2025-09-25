# DWRITE_MATRIX structure

## Description

The **DWRITE_MATRIX** structure specifies the graphics transform to be applied to rendered glyphs.

## Members

### `m11`

Type: **FLOAT**

A value indicating the horizontal scaling / cosine of rotation.

### `m12`

Type: **FLOAT**

A value indicating the vertical shear / sine of rotation.

### `m21`

Type: **FLOAT**

A value indicating the horizontal shear / negative sine of rotation.

### `m22`

Type: **FLOAT**

A value indicating the vertical scaling / cosine of rotation.

### `dx`

Type: **FLOAT**

A value indicating the horizontal shift (always orthogonal regardless of rotation).

### `dy`

Type: **FLOAT**

A value indicating the vertical shift (always orthogonal regardless of rotation.)