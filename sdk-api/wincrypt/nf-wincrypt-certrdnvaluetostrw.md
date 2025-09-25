# CertRDNValueToStrW function

## Description

The **CertRDNValueToStr** function converts a name in a
[CERT_RDN_VALUE_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) to a **null**-terminated character string.

## Parameters

### `dwValueType` [in]

Indicates the kind of RDN value to be converted.

This can be one of the following values:

* CERT_RDN_ANY_TYPE
* CERT_RDN_ENCODED_BLOB
* CERT_RDN_OCTET_STRING
* CERT_RDN_NUMERIC_STRING
* CERT_RDN_PRINTABLE_STRING
* CERT_RDN_TELETEX_STRING
* CERT_RDN_T61_STRING
* CERT_RDN_VIDEOTEX_STRING
* CERT_RDN_IA5_STRING
* CERT_RDN_GRAPHIC_STRING
* CERT_RDN_VISIBLE_STRING
* CERT_RDN_ISO646_STRING
* CERT_RDN_GENERAL_STRING
* CERT_RDN_UNIVERSAL_STRING
* CERT_RDN_INT4_STRING
* CERT_RDN_BMP_STRING
* CERT_RDN_UNICODE_STRING
* CERT_RDN_UTF8_STRING

### `pValue` [in]

A pointer to an
[CERT_RDN_VALUE_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) of a type appropriate for the *dwValueType*.

### `psz` [out]

A pointer to a buffer to receive the returned string.

### `csz` [in]

Size, in characters, allocated for the returned string. The size must include the terminating **NULL** character.

## Return value

Returns the number of characters converted, including the terminating **NULL** character. If *psz* is **NULL** or *csz* is zero, returns the required size of the destination string.

## Remarks

If *psz* is not **NULL** and *csz* is not zero, the returned *psz* is always a possibly empty **null**-terminated string.

> [!NOTE]
> The wincrypt.h header defines CertRDNValueToStr as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra)

[Data Conversion Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)