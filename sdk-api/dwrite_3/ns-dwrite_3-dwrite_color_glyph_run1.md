# DWRITE_COLOR_GLYPH_RUN1 structure

## Description

Represents a color glyph run. The IDWriteFactory4::TranslateColorGlyphRun method returns an ordered collection of color glyph runs of varying types depending on what the font supports.

## Members

### `glyphImageFormat`

Type of glyph image format for this color run. Exactly one type will be set since TranslateColorGlyphRun has already broken down the run into separate parts.

### `measuringMode`

Measuring mode to use for this glyph run.

### `DWRITE_COLOR_GLYPH_RUN`