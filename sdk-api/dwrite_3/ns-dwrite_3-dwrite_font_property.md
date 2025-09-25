# DWRITE_FONT_PROPERTY structure

## Description

Font property used for filtering font sets and
building a font set with explicit properties.

## Members

### `propertyId`

Specifies the requested font property, such as DWRITE_FONT_PROPERTY_ID_FAMILY_NAME.

### `propertyValue`

Specifies the value, such as "Segoe UI".

### `localeName`

Specifies the locale to use, such as "en-US". Simply leave this empty when used
with the font set filtering functions, as they will find a match regardless of
language. For passing to AddFontFaceReference, the localeName specifies the language
of the property value.