# _D3DSHADER_PARAM_REGISTER_TYPE enumeration

## Description

Pixel and vertex shader operations specify shader register types in bits 28, 29, 30, 11, and 12 of destination and source parameter tokens. The following register types can be specified:

## Constants

### `D3DSPR_TEMP`

Temporary register file.

### `D3DSPR_INPUT`

Input register file.

### `D3DSPR_CONST`

For PS, constant register file 0 - 2047 (DEF instruction). For VS, reserved.

### `D3DSPR_ADDR`

Address register (VS).

### `D3DSPR_TEXTURE`

Texture register file (PS).

### `D3DSPR_RASTOUT`

For VS, rasterizer output register file.

### `D3DSPR_ATTROUT`

Attribute output register file.

### `D3DSPR_TEXCRDOUT`

Texture coordinate output register file.

### `D3DSPR_OUTPUT`

For < VS 3_0, texture coordinate output register file. For >/= VS 3_0, output register file. For PS, reserved.

### `D3DSPR_CONSTINT`

Constant integer vector register file.

### `D3DSPR_COLOROUT`

Color output register file.

### `D3DSPR_DEPTHOUT`

Depth output register file.

### `D3DSPR_SAMPLER`

Sampler state register file.

### `D3DSPR_CONST2`

Constant register file 2048 - 4095.

### `D3DSPR_CONST3`

Constant register file 4096 - 6143.

### `D3DSPR_CONST4`

Constant register file 6144 - 8191.

### `D3DSPR_CONSTBOOL`

Constant Boolean register file.

### `D3DSPR_LOOP`

Loop counter register file.

### `D3DSPR_TEMPFLOAT16`

16-bit float temp register file.

### `D3DSPR_MISCTYPE`

Miscellaneous (single) registers.

### `D3DSPR_LABEL`

Label.

### `D3DSPR_PREDICATE`

Predicate register.

### `D3DSPR_FORCE_DWORD`

Force 32-bit size enumeration.