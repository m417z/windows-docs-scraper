# CertStrToNameA function

## Description

The **CertStrToName** function converts a null-terminated [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) string to an encoded certificate name.

## Parameters

### `dwCertEncodingType` [in]

The [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that was used to encode the string. The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) identifier, contained in the high **WORD** of this value, is ignored by this function.

This parameter can be the following currently defined certificate encoding type.

| Value | Meaning |
| --- | --- |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate encoding. |

### `pszX500` [in]

A pointer to the null-terminated X.500 string to be converted. The format of this string is specified by the *dwStrType* parameter.

This string is expected to be formatted the same as the output from
the [CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra) function.

### `dwStrType` [in]

This parameter specifies the type of the string. This parameter also specifies other options for the contents of the string.

If no flags are combined with the string type specifier, the string can contain a comma (,) or a semicolon (;) as separators in the [relative distinguished name](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RDN) and a plus sign (+) as the separator in multiple RDN values.

Quotation marks ("") are supported. A quotation can be included in a quoted value by using two sets of quotation marks, for example, CN="User ""one""".

A value that starts with a number sign (#) is treated as [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) hexadecimal and converted to a **CERT_RDN_OCTET_STRING**. Embedded white space is ignored. For example, 1.2.3 = # AB CD 01 is the same as 1.2.3=#ABCD01.

White space that surrounds the keys, object identifiers, and values is ignored.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_SIMPLE_NAME_STR**<br><br>1 | This string type is not supported. |
| **CERT_OID_NAME_STR**<br><br>2 | Validates that the string type is supported. The string can be either an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) or an X.500 name. |
| **CERT_X500_NAME_STR**<br><br>3 | Identical to CERT_OID_NAME_STR. Validates that the string type is supported. The string can be either an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) or an X.500 name. |

The following options can also be combined with the value above to specify additional options for the string.

| Value | Meaning |
| --- | --- |
| **CERT_NAME_STR_COMMA_FLAG**<br><br>0x04000000 | Only a comma (,) is supported as the RDN separator. |
| **CERT_NAME_STR_SEMICOLON_FLAG**<br><br>0x40000000 | Only a semicolon (;) is supported as the RDN separator. |
| **CERT_NAME_STR_CRLF_FLAG**<br><br>0x08000000 | Only a backslash r (\r) or backslash n (\n) is supported as the RDN separator. |
| **CERT_NAME_STR_NO_PLUS_FLAG**<br><br>0x20000000 | The plus sign (+) is ignored as a separator, and multiple values per RDN are not supported. |
| **CERT_NAME_STR_NO_QUOTING_FLAG**<br><br>0x10000000 | Quoting is not supported. |
| **CERT_NAME_STR_REVERSE_FLAG**<br><br>0x02000000 | The order of the RDNs in a distinguished name is reversed before encoding. This flag is not set by default. |
| **CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG**<br><br>0x00020000 | The **CERT_RDN_T61_STRING** encoded value type is used instead of **CERT_RDN_UNICODE_STRING**. This flag can be used if all the Unicode characters are less than or equal to 0xFF. |
| **CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG**<br><br>0x00040000 | The **CERT_RDN_UTF8_STRING** encoded value type is used instead of **CERT_RDN_UNICODE_STRING**. |
| **CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG**<br><br>0x00080000 | Forces the X.500 key to be encoded as a UTF-8 (CERT_RDN_UTF8_STRING) string rather than as a printable Unicode (CERT_RDN_PRINTABLE_STRING) string. This is the default value for Microsoft certification authorities beginning with Windows Server 2003. |
| **CERT_NAME_STR_DISABLE_UTF8_DIR_STR_FLAG**<br><br>0x00100000 | Prevents forcing a printable Unicode (CERT_RDN_PRINTABLE_STRING) X.500 key to be encoded by using UTF-8 (CERT_RDN_UTF8_STRING). Use to enable encoding of X.500 keys as Unicode values when CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG is set. |
| **CERT_NAME_STR_ENABLE_PUNYCODE_FLAG**<br><br>0x00200000 | If the string contains an email RDN value, and the email address contains Unicode characters outside of the ASCII character set, the host name portion of the email address is encoded in Punycode. The resultant email address is then encoded as an [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) string. The Punycode encoding of the host name is performed on a label-by-label basis.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |

### `pvReserved` [in, optional]

Reserved for future use and must be **NULL**.

### `pbEncoded` [out]

A pointer to a buffer that receives the encoded structure.

The size of this buffer is specified in the *pcbEncoded* parameter.

This parameter can be **NULL** to obtain the required size of the buffer for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbEncoded` [in, out]

A pointer to a **DWORD** that, before calling the function, contains the size, in bytes, of the buffer pointed to by the *pbEncoded* parameter. When the function returns, the **DWORD** contains the number of bytes stored in the buffer.

If *pbEncoded* is **NULL**, the **DWORD** receives the size, in bytes, required for the buffer.

### `ppszError` [out, optional]

A pointer to a string pointer that receives additional error information about an input string that is not valid.

If the *pszX500* string is not valid, *ppszError* is updated by this function to point to the beginning of the character sequence that is not valid. If no errors are detected in the input string, *ppszError* is set to **NULL**.

If this information is not required, pass **NULL** for this parameter.

This parameter is updated for the following error codes returned from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

#### CRYPT_E_INVALID_X500_STRING

#### CRYPT_E_INVALID_NUMERIC_STRING

#### CRYPT_E_INVALID_PRINTABLE_STRING

#### CRYPT_E_INVALID_IA5_STRING

## Return value

Returns nonzero if successful or zero otherwise.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The following table contains the supported X.500 keys, their corresponding object identifier string, string identifier (from Wincrypt.h), and value types.

| Key | Object identifier string | String identifier | RDN value types |
| --- | --- | --- | --- |
| CN | 2.5.4.3 | szOID_COMMON_NAME | Printable<br><br>T61 |
| L | 2.5.4.7 | szOID_LOCALITY_NAME | Printable<br><br>T61 |
| O | 2.5.4.10 | szOID_ORGANIZATION_NAME | Printable<br><br>T61 |
| OU | 2.5.4.11 | szOID_ORGANIZATIONAL_UNIT_NAME | Printable<br><br>T61 |
| E<br><br>Email | 1.2.840.113549.1.9.1 | szOID_RSA_emailAddr | IA5 |
| C | 2.5.4.6 | szOID_COUNTRY_NAME | Printable |
| S<br><br>ST | 2.5.4.8 | szOID_STATE_OR_PROVINCE_NAME | Printable<br><br>T61 |
| STREET | 2.5.4.9 | szOID_STREET_ADDRESS | Printable<br><br>T61 |
| T<br><br>Title | 2.5.4.12 | szOID_TITLE | Printable<br><br>T61 |
| G<br><br>GivenName | 2.5.4.42 | szOID_GIVEN_NAME | Printable<br><br>T61 |
| I<br><br>Initials | 2.5.4.43 | szOID_INITIALS | Printable<br><br>T61 |
| SN | 2.5.4.4 | szOID_SUR_NAME | Printable<br><br>T61 |
| DC | 0.9.2342.19200300.100.1.25 | szOID_DOMAIN_COMPONENT | IA5<br><br>UTF8 |

If either Printable or T61 is allowed as the RDN value type for the key, Printable is automatically selected if the name string component is a member of the following character sets:

* A, B, …, Z
* a, b, …, z
* 0, 1, …, 9
* (space) ' ( ) + , - . / : = ?

The T61 types are UTF8 encoded.

#### Examples

For an example that uses this function, see
[Example C Program: Converting Names from Certificates to ASN.1 and Back](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-converting-names-from-certificates-to-asn1-and-back).

> [!NOTE]
> The wincrypt.h header defines CertStrToName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra)

[Data Conversion Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length)