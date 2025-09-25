# D2D1_ATLAS_PROP enumeration

## Description

Identifiers for properties of the [Atlas effect](https://learn.microsoft.com/windows/desktop/Direct2D/atlas).

## Constants

### `D2D1_ATLAS_PROP_INPUT_RECT:0`

The portion of the image passed to the next effect.
Type is D2D1_VECTOR_4F.
Default value is (-FLT_MAX, -FLT_MAX, FLT_MAX, FLT_MAX).

### `D2D1_ATLAS_PROP_INPUT_PADDING_RECT:1`

The maximum size sampled for the output rectangle.
Type is D2D1_VECTOR_4F.
Default value is (-FLT_MAX, -FLT_MAX, FLT_MAX, FLT_MAX).

### `D2D1_ATLAS_PROP_FORCE_DWORD:0xffffffff`