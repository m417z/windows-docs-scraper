# XPS_SIGN_FLAGS enumeration

## Description

Specifies whether markup compatibility detection must be run
before signing.

## Constants

### `XPS_SIGN_FLAGS_NONE:0`

The system will check for any markup compatibility elements before
signing the package. If any markup compatibility elements are found, the signing operation
fails with an **XPS_E_MARKUP_COMPATIBILITY_ELEMENTS** error.

### `XPS_SIGN_FLAGS_IGNORE_MARKUP_COMPATIBILITY:0x1`

The system will not check for any markup compatibility elements before
signing the package.

## See also

[IXpsSigningOptions::GetFlags](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssigningoptions-getflags)

[IXpsSigningOptions::SetFlags](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nf-xpsdigitalsignature-ixpssigningoptions-setflags)

[Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)