# CertGetNameStringW function

## Description

The **CertGetNameString** function obtains the subject or issuer name from a certificate
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure and converts it to a **null**-terminated character string.

## Parameters

### `pCertContext` [in]

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) certificate context that includes a subject and issuer name to be converted.

### `dwType` [in]

**DWORD** indicating how the name is to be found and how the output is to be formatted.

| Value | Meaning |
| --- | --- |
| **CERT_NAME_EMAIL_TYPE**<br><br>1 | If the certificate has a Subject Alternative Name extension or Issuer Alternative Name, uses the first rfc822Name choice. If no rfc822Name choice is found in the extension, uses the Subject Name field for the Email OID. If either rfc822Name or the Email OID is found, uses the string. Otherwise, returns an empty string (returned character count is 1). *pvTypePara* is not used and is set to **NULL**. |
| **CERT_NAME_RDN_TYPE**<br><br>2 | Converts the Subject Name BLOB by calling [CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra). *pvTypePara* points to a **DWORD** containing the *dwStrType* passed to **CertNameToStr**. If the Subject Name field is empty and the certificate has a Subject Alternative Name extension, uses the first directory Name choice from **CertNameToStr**. |
| **CERT_NAME_ATTR_TYPE**<br><br>3 | *pvTypePara* points to an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) specifying the name attribute to be returned. For example, if *pvTypePara* is szOID_COMMON_NAME, uses the Subject Name member. If the Subject Name member is empty and the certificate has a Subject Alternative Name extension, uses the first directoryName choice. |
| **CERT_NAME_SIMPLE_DISPLAY_TYPE**<br><br>4 | Iterates through the following list of name attributes and uses the Subject Name or the Subject Alternative Name extension for the first occurrence of: szOID_COMMON_NAME, szOID_ORGANIZATIONAL_UNIT_NAME, szOID_ORGANIZATION_NAME, or szOID_RSA_emailAddr. <br><br>If one of these attributes is not found, uses the Subject Alternative Name extension for a rfc822Name choice. If there is still no match, uses the first attribute.<br><br>*pvTypePara* is not used and is set to **NULL**. |
| **CERT_NAME_FRIENDLY_DISPLAY_TYPE**<br><br>5 | Checks the certificate for a CERT_FRIENDLY_NAME_PROP_ID property. If the certificate has this property, it is returned. If the certificate does not have the property, the CERT_NAME_SIMPLE_DISPLAY_TYPE is returned. |
| **CERT_NAME_DNS_TYPE**<br><br>6 | If the certificate has a Subject Alternative Name extension for issuer, Issuer Alternative Name, search for first DNSName choice. <br><br>If the DNSName choice is not found in the extension, search the Subject Name field for the CN OID, "2.5.4.3".<br><br>If the DNSName or CN OID is found, return the string. Otherwise, return an empty string. |
| **CERT_NAME_URL_TYPE**<br><br>7 | If the certificate has a Subject Alternative Name extension for issuer, Issuer Alternative Name, search for first URL choice. If the URL choice is found, return the string. Otherwise, return an empty string. |
| **CERT_NAME_UPN_TYPE**<br><br>8 | If the certificate has a Subject Alternative Name extension, search the OtherName choices looking for a pszObjId == szOID_NT_PRINCIPAL_NAME, ("1.3.6.1.4.1.311.20.2.3"). <br><br>If the UPN OID is found, decode the BLOB as a X509_UNICODE_ANY_STRING and return the decoded string. Otherwise, return an empty string. |

### `dwFlags` [in]

Indicates the type of processing needed.

| Value | Meaning |
| --- | --- |
| **CERT_NAME_ISSUER_FLAG**<br><br>0x1 | Acquires the issuer's name. If not set, acquires the subject's name. |
| **CERT_NAME_DISABLE_IE4_UTF8_FLAG**<br><br>0x00010000 | Skips the default initial attempt to decode the value as UTF8 and decodes as 8-bit characters. |
| **CERT_NAME_SEARCH_ALL_NAMES_FLAG**<br><br>0x2 | If the *dwType* parameter is set to **CERT_NAME_DNS_TYPE**, all applicable names are returned for the specified DNS value. If there is no DNS name but there is a CN component in the subject, the CN is returned instead. If there is a CN and a DNS name, only the DNS names are returned. This mimics the SSL chain building policy. If you set this flag for a name type other than **CERT_NAME_DNS_TYPE**, this function returns a null-terminated empty string.<br><br>**Windows 8 and Windows Server 2012:** Support for this flag begins. |
| **CERT_NAME_STR_ENABLE_PUNYCODE_FLAG**<br><br>0x00200000 | This flag enables decoding of [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) strings to Unicode string values based on the *dwType* parameter value as defined below:<br><br>* CERT_NAME_EMAIL_TYPE: If the host name portion of the email address contains a Punycode encoded [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) component, it is converted to the Unicode equivalent.<br>* CERT_NAME_SIMPLE_DISPLAY_TYPE: If a Subject Name of szOID_RSA_emailAddr or the rfc822Name from the Subject Alternative Name is returned from the certificate, and the host name portion of the email address a contains Punycode encoded [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) component, it is converted to the Unicode equivalent.<br>* CERT_NAME_DNS_TYPE: If the certificate has an Issuer Alternative Name, with a DNSName choice, and the host name portion of the email address a contains Punycode encoded [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) component, it is converted to the Unicode equivalent.<br>* CERT_NAME_URL_TYPE: The URI is decoded and unescaped. If the server host name of the URI contains a Punycode encoded [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string) component, the host name string is converted to the Unicode equivalent.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |

### `pvTypePara` [in]

A pointer to either a **DWORD** containing the *dwStrType* or an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) specifying the name attribute. The type pointed to is determined by the value of *dwType*.

### `pszNameString` [out]

A pointer to an allocated buffer to receive the returned string. If *pszNameString* is not **NULL** and *cchNameString* is not zero, *pszNameString* is a **null**-terminated string.

If **CERT_NAME_SEARCH_ALL_NAMES_FLAG** is specified in the *dwFlags* parameter and **CERT_NAME_DNS_TYPE** is set in the *dwType* parameter, the returned string will contain all of the DNS names that apply. Each string in the output string is null-terminated and the last string will be double null-terminated. If no DNS names are found, a single null-terminated empty string is returned.

### `cchNameString` [in]

Size, in characters, allocated for the returned string. The size must include the terminating **NULL** character.

## Return value

Returns the number of characters converted, including the terminating zero character. If *pszNameString* is **NULL** or *cchNameString* is zero, returns the required size of the destination string (including the terminating **NULL** character). If the specified name type is not found, returns a **null**-terminated empty string with a returned character count of 1.

## See also

[Data Conversion Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

## Remarks

> [!NOTE]
> The wincrypt.h header defines CertGetNameString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).