# XPS_FONT_EMBEDDING enumeration

## Description

Describes the option for embedding a font.

## Constants

### `XPS_FONT_EMBEDDING_NORMAL:1`

The embedded font is neither obfuscated nor restricted.

### `XPS_FONT_EMBEDDING_OBFUSCATED`

The embedded font is obfuscated but not restricted.

### `XPS_FONT_EMBEDDING_RESTRICTED`

The embedded font is obfuscated and restricted.

### `XPS_FONT_EMBEDDING_RESTRICTED_UNOBFUSCATED`

The font is restricted but not obfuscated.

This value cannot be set by an application. It is set when the document being deserialized contains a restricted font that is not obfuscated. Restricted fonts should be obfuscated, so this value usually indicates an error in the application that created the XPS document being deserialized.

## See also

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)