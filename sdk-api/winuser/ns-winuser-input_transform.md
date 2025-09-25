# INPUT_TRANSFORM structure

## Description

Defines the matrix that represents a transform on a message consumer. This matrix can be used to transform pointer input data from client coordinates to screen coordinates, while the inverse can be used to transform pointer input data from screen coordinates to client coordinates.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._11`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._12`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._13`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._14`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._21`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._22`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._23`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._24`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._31`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._32`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._33`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._34`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._41`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._42`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._43`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME._44`

### `DUMMYUNIONNAME.m`

#### - ( unnamed struct )

A 4x4 matrix, represented as a linear sequence of fields.

#### _11

The first floating-point column value in the first row of the matrix.

#### _12

The second floating-point column value in the first row of the matrix.

#### _13

The third floating-point column value in the first row of the matrix.

#### _14

The fourth floating-point column value in the first row of the matrix.

#### _21

The first floating-point column value in the second row of the matrix.

#### _22

The second floating-point column value in the second row of the matrix.

#### _23

The third floating-point column value in the second row of the matrix.

#### _24

The fourth floating-point column value in the second row of the matrix.

#### _31

The first floating-point column value in the third row of the matrix.

#### _32

The second floating-point column value in the third row of the matrix.

#### _33

The third floating-point column value in the third row of the matrix.

#### _34

The fourth floating-point column value in the third row of the matrix.

#### _41

The first floating-point column value in the fourth row of the matrix.

#### _42

The second floating-point column value in the fourth row of the matrix.

#### _43

The third floating-point column value in the fourth row of the matrix.

#### _44

The fourth floating-point column value in the fourth row of the matrix.

#### - m[4][4]

A 4x4 matrix, represented as a two-dimensional array.

## See also

[GetPointerInputTransform](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinputtransform)

[Structures](https://learn.microsoft.com/windows/win32/inputmsg/structures)