# DWRITE_FONT_SIMULATIONS enumeration

## Description

Specifies algorithmic style simulations to be applied to the font face. Bold and oblique simulations can be combined via bitwise OR operation.

## Constants

### `DWRITE_FONT_SIMULATIONS_NONE:0x0000`

Indicates that no simulations are applied to the font face.

### `DWRITE_FONT_SIMULATIONS_BOLD:0x0001`

Indicates that algorithmic emboldening is applied to the font face. [DWRITE_FONT_SIMULATIONS_BOLD](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_simulations) increases weight by applying a widening algorithm to the glyph outline. This may be used to simulate a bold weight where no designed bold weight is available.

### `DWRITE_FONT_SIMULATIONS_OBLIQUE:0x0002`

Indicates that algorithmic italicization is applied to the font face. [DWRITE_FONT_SIMULATIONS_OBLIQUE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_simulations) applies obliquing (shear) to the glyph outline. This may be used to simulate an oblique/italic style where no designed oblique/italic style is available.

## Remarks

Style simulations are not recommended for good typographic quality.