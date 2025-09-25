# DWRITE_INLINE_OBJECT_METRICS structure

## Description

Contains properties describing the geometric measurement of an
application-defined inline object.

## Members

### `width`

Type: **FLOAT**

The width of the inline object.

### `height`

Type: **FLOAT**

The height of the inline object.

### `baseline`

Type: **FLOAT**

The distance from the top of the object to the point where it is lined up with the adjacent text.
If the baseline is at the bottom, then **baseline** simply equals **height**.

### `supportsSideways`

Type: **BOOL**

A Boolean flag that indicates whether the object is to be placed upright or alongside the text baseline for vertical text.