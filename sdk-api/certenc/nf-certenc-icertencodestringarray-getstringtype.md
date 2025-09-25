# ICertEncodeStringArray::GetStringType

## Description

The **GetStringType** method returns the type of string values that the string array contains.

## Parameters

### `pStringType` [out]

A pointer to a **Long** that represents the string type. For a list of string types, see Remarks.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value indicates the type of strings in the string array. For a list of string types, see Remarks.

## Remarks

The following table lists the types of strings that the string array can contain. For more information about RDN types, see the CryptoAPI 2.0 documents.

| String type | Meaning |
| --- | --- |
| CERT_RDN_ANY_TYPE | For encoding an X509_UNICODE_NAME name. |
| CERT_RDN_NUMERIC_STRING | The numerals 0 through 9 and the space character (8 bit). |
| CERT_RDN_PRINTABLE_STRING | Printable characters (8 bit). |
| CERT_RDN_T61_STRING | T.61 encoded characters (8 bit). |
| CERT_RDN_VIDEOTEX_STRING | VIDEOTEX characters. |
| CERT_RDN_IA5_STRING | IA5 (ASCII) characters. |
| CERT_RDN_GRAPHIC_STRING | A string of ISO-defined GRAPHIC characters. |
| CERT_RDN_ISO646_STRING | 128 character set (8 bit). |
| CERT_RDN_GENERAL_STRING | A string of ISO-defined GENERAL characters. |
| CERT_RDN_INT4_STRING | An array of INT4 values (32 bit). |
| CERT_RDN_UNICODE_STRING | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) characters (16 bit). |

#### Examples

For an example that uses the **GetStringType** method, see the [ICertEncodeStringArray::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-encode) method.

## See also

[ICertEncodeStringArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodestringarray)

[ICertEncodeStringArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-reset)