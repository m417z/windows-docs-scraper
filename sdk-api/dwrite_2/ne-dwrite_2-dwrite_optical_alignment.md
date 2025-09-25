# DWRITE_OPTICAL_ALIGNMENT enumeration

## Description

The optical margin alignment mode.

By default, glyphs are aligned to the margin by the default origin and side-bearings of the glyph.
If you specify **DWRITE_OPTICAL_ALIGNMENT_NO_SIDE_BEARINGS**, then the alignment uses the side bearings to offset the glyph
from the aligned edge to ensure the ink of the glyphs are aligned.

## Constants

### `DWRITE_OPTICAL_ALIGNMENT_NONE`

Align to the default origin and side-bearings of the glyph.

### `DWRITE_OPTICAL_ALIGNMENT_NO_SIDE_BEARINGS`

Align to the ink of the glyphs, such that the black box abuts the margins.