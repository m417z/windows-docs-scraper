# DWRITE_INFORMATIONAL_STRING_ID enumeration

## Description

The informational string enumeration which identifies a string embedded in a font file.

## Constants

### `DWRITE_INFORMATIONAL_STRING_NONE`

Indicates the string containing the unspecified name ID.

### `DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE`

Indicates the string containing the copyright notice provided by the font.

### `DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS`

Indicates the string containing a version number.

### `DWRITE_INFORMATIONAL_STRING_TRADEMARK`

Indicates the string containing the trademark information provided by the font.

### `DWRITE_INFORMATIONAL_STRING_MANUFACTURER`

Indicates the string containing the name of the font manufacturer.

### `DWRITE_INFORMATIONAL_STRING_DESIGNER`

Indicates the string containing the name of the font designer.

### `DWRITE_INFORMATIONAL_STRING_DESIGNER_URL`

Indicates the string containing the URL of the font designer (with protocol, e.g., http://, ftp://).

### `DWRITE_INFORMATIONAL_STRING_DESCRIPTION`

Indicates the string containing the description of the font. This may also contain revision information, usage recommendations, history, features, and so on.

### `DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL`

Indicates the string containing the URL of the font vendor (with protocol, e.g., http://, ftp://). If a unique serial number is embedded in the URL, it can be used to register the font.

### `DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION`

Indicates the string containing the description of how the font may be legally used, or different example scenarios for licensed use.

### `DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL`

Indicates the string containing the URL where additional licensing information can be found.

### `DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES`

Indicates the string containing the GDI-compatible family name. Since GDI allows a maximum of four fonts per family, fonts in the same family may have different GDI-compatible family names (e.g., "Arial", "Arial Narrow", "Arial Black").

### `DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES`

Indicates the string containing a GDI-compatible subfamily name.

### `DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_FAMILY_NAMES`

### `DWRITE_INFORMATIONAL_STRING_TYPOGRAPHIC_SUBFAMILY_NAMES`

### `DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT`

Contains sample text for display in font lists. This can be the font name or any other text that the designer thinks is the best

example to display the font in.

### `DWRITE_INFORMATIONAL_STRING_FULL_NAME`

The full name of the font, like Arial Bold, from *name id 4* in the name table

### `DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME`

The postscript name of the font, like GillSans-Bold, from *name id 6* in the name table.

### `DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_CID_NAME`

The postscript CID findfont name, from *name id 20* in the name table

### `DWRITE_INFORMATIONAL_STRING_WEIGHT_STRETCH_STYLE_FAMILY_NAME`

### `DWRITE_INFORMATIONAL_STRING_DESIGN_SCRIPT_LANGUAGE_TAG`

### `DWRITE_INFORMATIONAL_STRING_SUPPORTED_SCRIPT_LANGUAGE_TAG`

### `DWRITE_INFORMATIONAL_STRING_PREFERRED_FAMILY_NAMES`

Indicates the string containing the family name preferred by the designer. This enables font designers to group more than four fonts in a single family without losing compatibility with GDI. This name is typically only present if it differs from the GDI-compatible family name.

### `DWRITE_INFORMATIONAL_STRING_PREFERRED_SUBFAMILY_NAMES`

Indicates the string containing the subfamily name preferred by the designer. This name is typically only present if it differs from the GDI-compatible subfamily name.

### `DWRITE_INFORMATIONAL_STRING_WWS_FAMILY_NAME`