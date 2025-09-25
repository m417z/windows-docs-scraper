# PANOSE structure

## Description

The **PANOSE** structure describes the PANOSE font-classification values for a TrueType font. These characteristics are then used to associate the font with other fonts of similar appearance but different names.

## Members

### `bFamilyType`

For Latin fonts, one of one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_FAMILY_TEXT_DISPLAY | Text and display |
| PAN_FAMILY_SCRIPT | Script |
| PAN_FAMILY_DECORATIVE | Decorative |
| PAN_FAMILY_PICTORIAL | Pictorial |

### `bSerifStyle`

The serif style. For Latin fonts, one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_SERIF_COVE | Cove |
| PAN_SERIF_OBTUSE_COVE | Obtuse cove |
| PAN_SERIF_SQUARE_COVE | Square cove |
| PAN_SERIF_OBTUSE_SQUARE_COVE | Obtuse square cove |
| PAN_SERIF_SQUARE | Square |
| PAN_SERIF_THIN | Thin |
| PAN_SERIF_BONE | Bone |
| PAN_SERIF_EXAGGERATED | Exaggerated |
| PAN_SERIF_TRIANGLE | Triangle |
| PAN_SERIF_NORMAL_SANS | Normal sans serif |
| PAN_SERIF_OBTUSE_SANS | Obtuse sans serif |
| PAN_SERIF_PERP_SANS | Perp sans serif |
| PAN_SERIF_FLARED | Flared |
| PAN_SERIF_ROUNDED | Rounded |

### `bWeight`

For Latin fonts, one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_WEIGHT_VERY_LIGHT | Very light |
| PAN_WEIGHT_LIGHT | Light |
| PAN_WEIGHT_THIN | Thin |
| PAN_WEIGHT_BOOK | Book |
| PAN_WEIGHT_MEDIUM | Medium |
| PAN_WEIGHT_DEMI | Demibold |
| PAN_WEIGHT_BOLD | Bold |
| PAN_WEIGHT_HEAVY | Heavy |
| PAN_WEIGHT_BLACK | Black |
| PAN_WEIGHT_NORD | Nord |

### `bProportion`

For Latin fonts, one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_PROP_OLD_STYLE | Old style |
| PAN_PROP_MODERN | Modern |
| PAN_PROP_EVEN_WIDTH | Even width |
| PAN_PROP_EXPANDED | Expanded |
| PAN_PROP_CONDENSED | Condensed |
| PAN_PROP_VERY_EXPANDED | Very expanded |
| PAN_PROP_VERY_CONDENSED | Very condensed |
| PAN_PROP_MONOSPACED | Monospaced |

### `bContrast`

For Latin fonts, one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_CONTRAST_NONE | None |
| PAN_CONTRAST_VERY_LOW | Very low |
| PAN_CONTRAST_LOW | Low |
| PAN_CONTRAST_MEDIUM_LOW | Medium low |
| PAN_CONTRAST_MEDIUM | Medium |
| PAN_CONTRAST_MEDIUM_HIGH | Medium high |
| PAN_CONTRAST_HIGH | High |
| PAN_CONTRAST_VERY_HIGH | Very high |

### `bStrokeVariation`

For Latin fonts, one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_STROKE_GRADUAL_DIAG | Gradual/diagonal |
| PAN_STROKE_GRADUAL_TRAN | Gradual/transitional |
| PAN_STROKE_GRADUAL_VERT | Gradual/vertical |
| PAN_STROKE_GRADUAL_HORZ | Gradual/horizontal |
| PAN_STROKE_RAPID_VERT | Rapid/vertical |
| PAN_STROKE_RAPID_HORZ | Rapid/horizontal |
| PAN_STROKE_INSTANT_VERT | Instant/vertical |

### `bArmStyle`

For Latin fonts, one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_STRAIGHT_ARMS_HORZ | Straight arms/horizontal |
| PAN_STRAIGHT_ARMS_WEDGE | Straight arms/wedge |
| PAN_STRAIGHT_ARMS_VERT | Straight arms/vertical |
| PAN_STRAIGHT_ARMS_SINGLE_SERIF | Straight arms/single-serif |
| PAN_STRAIGHT_ARMS_DOUBLE_SERIF | Straight arms/double-serif |
| PAN_BENT_ARMS_HORZ | Nonstraight arms/horizontal |
| PAN_BENT_ARMS_WEDGE | Nonstraight arms/wedge |
| PAN_BENT_ARMS_VERT | Nonstraight arms/vertical |
| PAN_BENT_ARMS_SINGLE_SERIF | Nonstraight arms/single-serif |
| PAN_BENT_ARMS_DOUBLE_SERIF | Nonstraight arms/double-serif |

### `bLetterform`

For Latin fonts, one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_LETT_NORMAL_CONTACT | Normal/contact |
| PAN_LETT_NORMAL_WEIGHTED | Normal/weighted |
| PAN_LETT_NORMAL_BOXED | Normal/boxed |
| PAN_LETT_NORMAL_FLATTENED | Normal/flattened |
| PAN_LETT_NORMAL_ROUNDED | Normal/rounded |
| PAN_LETT_NORMAL_OFF_CENTER | Normal/off center |
| PAN_LETT_NORMAL_SQUARE | Normal/square |
| PAN_LETT_OBLIQUE_CONTACT | Oblique/contact |
| PAN_LETT_OBLIQUE_WEIGHTED | Oblique/weighted |
| PAN_LETT_OBLIQUE_BOXED | Oblique/boxed |
| PAN_LETT_OBLIQUE_FLATTENED | Oblique/flattened |
| PAN_LETT_OBLIQUE_ROUNDED | Oblique/rounded |
| PAN_LETT_OBLIQUE_OFF_CENTER | Oblique/off center |
| PAN_LETT_OBLIQUE_SQUARE | Oblique/square |

### `bMidline`

For Latin fonts, one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_MIDLINE_STANDARD_TRIMMED | Standard/trimmed |
| PAN_MIDLINE_STANDARD_POINTED | Standard/pointed |
| PAN_MIDLINE_STANDARD_SERIFED | Standard/serifed |
| PAN_MIDLINE_HIGH_TRIMMED | High/trimmed |
| PAN_MIDLINE_HIGH_POINTED | High/pointed |
| PAN_MIDLINE_HIGH_SERIFED | High/serifed |
| PAN_MIDLINE_CONSTANT_TRIMMED | Constant/trimmed |
| PAN_MIDLINE_CONSTANT_POINTED | Constant/pointed |
| PAN_MIDLINE_CONSTANT_SERIFED | Constant/serifed |
| PAN_MIDLINE_LOW_TRIMMED | Low/trimmed |
| PAN_MIDLINE_LOW_POINTED | Low/pointed |
| PAN_MIDLINE_LOW_SERIFED | Low/serifed |

### `bXHeight`

For Latin fonts, one of the following values.

| Value | Meaning |
| --- | --- |
| PAN_ANY | Any |
| PAN_NO_FIT | No fit |
| PAN_XHEIGHT_CONSTANT_SMALL | Constant/small |
| PAN_XHEIGHT_CONSTANT_STD | Constant/standard |
| PAN_XHEIGHT_CONSTANT_LARGE | Constant/large |
| PAN_XHEIGHT_DUCKING_SMALL | Ducking/small |
| PAN_XHEIGHT_DUCKING_STD | Ducking/standard |
| PAN_XHEIGHT_DUCKING_LARGE | Ducking/large |

## See also

[EXTLOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-extlogfonta)

[Font and Text Structures](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-structures)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica)