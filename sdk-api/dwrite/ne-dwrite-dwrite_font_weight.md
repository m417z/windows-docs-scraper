# DWRITE_FONT_WEIGHT enumeration

## Description

Represents the density of a typeface, in terms of the lightness or heaviness of the strokes. The enumerated values correspond to the usWeightClass definition in the OpenType specification. The *usWeightClass* represents an integer value between 1 and 999. Lower values indicate lighter weights; higher values indicate heavier weights.

## Constants

### `DWRITE_FONT_WEIGHT_THIN:100`

Predefined font weight : Thin (100).

### `DWRITE_FONT_WEIGHT_EXTRA_LIGHT:200`

Predefined font weight : Extra-light (200).

### `DWRITE_FONT_WEIGHT_ULTRA_LIGHT:200`

Predefined font weight : Ultra-light (200).

### `DWRITE_FONT_WEIGHT_LIGHT:300`

Predefined font weight : Light (300).

### `DWRITE_FONT_WEIGHT_SEMI_LIGHT:350`

Predefined font weight : Semi-Light (350).

### `DWRITE_FONT_WEIGHT_NORMAL:400`

Predefined font weight : Normal (400).

### `DWRITE_FONT_WEIGHT_REGULAR:400`

Predefined font weight : Regular (400).

### `DWRITE_FONT_WEIGHT_MEDIUM:500`

Predefined font weight : Medium (500).

### `DWRITE_FONT_WEIGHT_DEMI_BOLD:600`

Predefined font weight : Demi-bold (600).

### `DWRITE_FONT_WEIGHT_SEMI_BOLD:600`

Predefined font weight : Semi-bold (600).

### `DWRITE_FONT_WEIGHT_BOLD:700`

Predefined font weight : Bold (700).

### `DWRITE_FONT_WEIGHT_EXTRA_BOLD:800`

Predefined font weight : Extra-bold (800).

### `DWRITE_FONT_WEIGHT_ULTRA_BOLD:800`

Predefined font weight : Ultra-bold (800).

### `DWRITE_FONT_WEIGHT_BLACK:900`

Predefined font weight : Black (900).

### `DWRITE_FONT_WEIGHT_HEAVY:900`

Predefined font weight : Heavy (900).

### `DWRITE_FONT_WEIGHT_EXTRA_BLACK:950`

Predefined font weight : Extra-black (950).

### `DWRITE_FONT_WEIGHT_ULTRA_BLACK:950`

Predefined font weight : Ultra-black (950).

## Remarks

Weight differences are generally differentiated by an increased stroke or thickness that is associated with a given character in a typeface, as compared to a "normal" character from that same typeface.
The following illustration shows an example of Normal and UltraBold weights for the Palatino Linotype typeface.

![Illustration of the letter "W" in Normal and UltraBold weights](https://learn.microsoft.com/windows/win32/api/dwrite/images/FontWeight_for_Palatino.png)

**Note** Not all weights are available for all typefaces. When a weight is not available for a typeface, the closest matching weight is returned.

Font weight values less than 1 or greater than 999 are considered invalid, and they are rejected by font API functions.