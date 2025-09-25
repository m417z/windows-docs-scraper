# _EXTTEXTMETRIC structure

## Description

The EXTTEXTMETRIC structure is used to specify font-specific information within [Unidrv font metrics files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.ufm files).

## Members

### `emSize`

Specifies the size of the structure, in bytes.

### `emPointSize`

Specifies the nominal point size of this font, in twips (1/20 of a point, or 1/1440 inch). This is the intended size of the font; the actual size may differ slightly depending on the resolution of the device.

### `emOrientation`

Specifies the orientation of the font. The **emOrientation** member can be any of the following values:

| Value | Meaning |
| --- | --- |
| 0 | Either portrait or landscape orientation |
| 1 | Portrait orientation |
| 2 | Landscape orientation |

### `emMasterHeight`

Specifies the font size, in device units, for which the values in this font's extent table are exact.

### `emMinScale`

Specifies the minimum valid point size for this font. The following equation illustrates how the minimum point size is determined:

```cpp
smallest point size = (emMinScale * 72) / dfVertRes
```

The value 72 represents the number of points per inch. The *dfVertRes* value is the number of dots per inch.

### `emMaxScale`

Specifies the maximum valid point size for this font. The following equation illustrates how the maximum point size is determined:

```cpp
largest point size = (etmMaxScale * 72) / dfVertRes
```

The value 72 represents the number of points per inch. The *dfVertRes* value is the number of dots per inch.

### `emMasterUnits`

Specifies the integral number of units per em, where an em equals the value of the **emMasterHeight** member. (That is, **emMasterUnits** is **emMasterHeight** expressed in font units instead of device units.)

### `emCapHeight`

Specifies the height, in font units, of uppercase characters in the font. Typically, this is the height of uppercase H.

### `emXHeight`

Specifies the height, in font units, of lowercase characters in the font. Typically, this is the height of lowercase x.

### `emLowerCaseAscent`

Specifies the distance, in font units, that the ascender of lowercase letters extends above the base line. Typically, this is the height of lowercase d.

### `emLowerCaseDescent`

Specifies the distance, in font units, that the descender of lowercase letters extends below the base line. Typically, this is specified for the descender of lowercase p.

### `emSlant`

For an italic or slanted font, specifies the angle of the slant measured in tenths of a degree clockwise from the upright version of the font.

### `emSuperScript`

Specifies the recommended amount, in font units, to offset superscript characters from the base line. This is typically a negative value.

### `emSubScript`

Specifies the recommended amount, in font units, to offset subscript characters from the base line. This is typically a positive value.

### `emSuperScriptSize`

Specifies the recommended size, in font units, of superscript characters for this font.

### `emSubScriptSize`

Specifies the recommended size, in font units, of subscript characters for this font.

### `emUnderlineOffset`

Specifies the offset, in font units, downward from the base line, where the top of a single underline bar should appear.

### `emUnderlineWidth`

Specifies the thickness, in font units, of the underline bar.

### `emDoubleUpperUnderlineOffset`

Specifies the offset, in font units, downward from the base line, where the top of the upper double-underline bar should appear.

### `emDoubleLowerUnderlineOffset`

Specifies the offset, in font units, downward from the base line, where the top of the lower double-underline bar should appear.

### `emDoubleUpperUnderlineWidth`

Specifies the thickness, in font units, of the upper underline bar.

### `emDoubleLowerUnderlineWidth`

Specifies the thickness, in font units, of the lower underline bar.

### `emStrikeOutOffset`

Specifies the offset, in font units, upward from the base line, where the top of a strikeout bar should appear.

### `emStrikeOutWidth`

Specifies the thickness, in font units, of the strikeout bar.

### `emKernPairs`

Specifies the number of character kerning pairs defined for this font.

### `emKernTracks`

Specifies the number of kerning tracks defined for this font.