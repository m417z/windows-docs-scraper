# ICertEncodeStringArray::Reset

## Description

The **Reset** method specifies the size of the string array and the type of strings the array will contain.The values of all the elements in the string array are set to zero.

You must call this method before calling the [ICertEncodeStringArray::SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-setvalue) method for the first time.

## Parameters

### `Count` [in]

Specifies the number of elements in the string array.

### `StringType` [in]

Specifies the type of strings that the string array contains. The type must be one of the following values. For more information about RDN types, see the CryptoAPI 2.0 documents.

| Value | Meaning |
| --- | --- |
| **CERT_RDN_ANY_TYPE** | For encoding an X509_UNICODE_NAME name. |
| **CERT_RDN_NUMERIC_STRING** | The characters 0 through 9 and the space character (8 bit). |
| **CERT_RDN_PRINTABLE_STRING** | Printable characters (8 bit). |
| **CERT_RDN_T61_STRING** | T.61 encoded characters (8 bit). |
| **CERT_RDN_VIDEOTEX_STRING** | VIDEOTEX characters. |
| **CERT_RDN_IA5_STRING** | IA5 (ASCII) characters. |
| **CERT_RDN_GRAPHIC_STRING** | A string of ISO-defined GRAPHIC characters. |
| **CERT_RDN_ISO646_STRING** | 128 character set (8 bit). |
| **CERT_RDN_GENERAL_STRING** | A string of ISO-defined GENERAL characters. |
| **CERT_RDN_INT4_STRING** | An array of INT4 values (32 bit). |
| **CERT_RDN_UNICODE_STRING** | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) characters (16 bit). |

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertEncodeStringArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodestringarray)