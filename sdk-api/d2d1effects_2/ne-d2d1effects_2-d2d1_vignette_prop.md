# D2D1_VIGNETTE_PROP enumeration

## Description

Identifiers for properties of the [Vignette effect](https://learn.microsoft.com/windows/desktop/Direct2D/vignette-effect).

## Constants

### `D2D1_VIGNETTE_PROP_COLOR:0`

The D2D1_VIGNETTE_PROP_COLOR property is an RGB triplet that specifies the color to fade the image's edges to. The default color is black.

### `D2D1_VIGNETTE_PROP_TRANSITION_SIZE:1`

The D2D1_VIGNETTE_PROP_TRANSITION_SIZE property is a float value that specifies the size of the vignette region as a percentage of the full image region.
A size of 0 means the unfaded region is the entire image, while a size of 1 means the faded region is the entire source image.
The allowed range is 0.0 to 1.0. The default value is 0.1.

### `D2D1_VIGNETTE_PROP_STRENGTH:2`

The D2D1_VIGNETTE_PROP_STRENGTH property is a float value that specifies how much the vignette color bleeds in for a given transition size.
The allowed range is 0.0 to 1.0. The default value is 0.5.

### `D2D1_VIGNETTE_PROP_FORCE_DWORD:0xffffffff`