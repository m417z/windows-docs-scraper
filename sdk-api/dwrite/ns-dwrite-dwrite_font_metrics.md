# DWRITE_FONT_METRICS structure

## Description

The **DWRITE_FONT_METRICS** structure specifies the metrics that are applicable to all glyphs within the font face.

## Members

### `designUnitsPerEm`

Type: **UINT16**

The number of font design units per em unit. Font files use their own coordinate system of font design units. A font design unit is the smallest measurable unit in the em square, an imaginary square that is used to size and align glyphs. The concept of em square is used as a reference scale factor when defining font size and device transformation semantics. The size of one em square is also commonly used to compute the paragraph indentation value.

### `ascent`

Type: **UINT16**

The ascent value of the font face in font design units. Ascent is the distance from the top of font character alignment box to the English baseline.

### `descent`

Type: **UINT16**

The descent value of the font face in font design units. Descent is the distance from the bottom of font character alignment box to the English baseline.

### `lineGap`

Type: **INT16**

The line gap in font design units. Recommended additional white space to add between lines to improve legibility. The recommended line spacing (baseline-to-baseline distance) is the sum of **ascent**, **descent**, and **lineGap**. The line gap is usually positive or zero but can be negative, in which case the recommended line spacing is less than the height of the character alignment box.

### `capHeight`

Type: **UINT16**

The cap height value of the font face in font design units. Cap height is the distance from the English baseline to the top of a typical English capital. Capital "H" is often used as a reference character for the purpose of calculating the cap height value.

### `xHeight`

Type: **UINT16**

The x-height value of the font face in font design units. x-height is the distance from the English baseline to the top of lowercase letter "x", or a similar lowercase character.

### `underlinePosition`

Type: **INT16**

The underline position value of the font face in font design units. Underline position is the position of underline relative to the English baseline. The value is usually made negative in order to place the underline below the baseline.

### `underlineThickness`

Type: **UINT16**

The suggested underline thickness value of the font face in font design units.

### `strikethroughPosition`

Type: **INT16**

The strikethrough position value of the font face in font design units. Strikethrough position is the position of strikethrough relative to the English baseline. The value is usually made positive in order to place the strikethrough above the baseline.

### `strikethroughThickness`

Type: **UINT16**

The suggested strikethrough thickness value of the font face in font design units.