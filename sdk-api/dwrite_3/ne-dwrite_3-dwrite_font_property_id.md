# DWRITE_FONT_PROPERTY_ID enumeration

## Description

Identifies a string in a font.

## Constants

### `DWRITE_FONT_PROPERTY_ID_NONE`

Unspecified font property identifier.

### `DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FAMILY_NAME`

### `DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FAMILY_NAME`

### `DWRITE_FONT_PROPERTY_ID_WEIGHT_STRETCH_STYLE_FACE_NAME`

### `DWRITE_FONT_PROPERTY_ID_FULL_NAME`

The full name of the font, for example "Arial Bold", from name id 4 in the name table.

### `DWRITE_FONT_PROPERTY_ID_WIN32_FAMILY_NAME`

GDI-compatible family name. Because GDI allows a maximum of four fonts per family, fonts in the same family may have different GDI-compatible family names,
for example "Arial", "Arial Narrow", "Arial Black".

### `DWRITE_FONT_PROPERTY_ID_POSTSCRIPT_NAME`

The postscript name of the font, for example "GillSans-Bold", from name id 6 in the name table.

### `DWRITE_FONT_PROPERTY_ID_DESIGN_SCRIPT_LANGUAGE_TAG`

Script/language tag to identify the scripts or languages that the font was primarily designed to support.

### `DWRITE_FONT_PROPERTY_ID_SUPPORTED_SCRIPT_LANGUAGE_TAG`

Script/language tag to identify the scripts or languages that the font declares it is able to support.

### `DWRITE_FONT_PROPERTY_ID_SEMANTIC_TAG`

Semantic tag to describe the font, for example Fancy, Decorative, Handmade, Sans-serif, Swiss, Pixel, Futuristic.

### `DWRITE_FONT_PROPERTY_ID_WEIGHT`

Weight of the font represented as a decimal string in the range 1-999.

### `DWRITE_FONT_PROPERTY_ID_STRETCH`

Stretch of the font represented as a decimal string in the range 1-9.

### `DWRITE_FONT_PROPERTY_ID_STYLE`

Style of the font represented as a decimal string in the range 0-2.

### `DWRITE_FONT_PROPERTY_ID_TYPOGRAPHIC_FACE_NAME`

### `DWRITE_FONT_PROPERTY_ID_TOTAL`

Total number of properties.

### `DWRITE_FONT_PROPERTY_ID_TOTAL_RS3`

### `DWRITE_FONT_PROPERTY_ID_PREFERRED_FAMILY_NAME`

Family name preferred by the designer. This enables font designers to group more than four fonts in a single family without losing compatibility with
GDI. This name is typically only present if it differs from the GDI-compatible family name.

### `DWRITE_FONT_PROPERTY_ID_FAMILY_NAME`

Family name for the weight-width-slope model.

### `DWRITE_FONT_PROPERTY_ID_FACE_NAME`

Face name of the font, for example Regular or Bold.