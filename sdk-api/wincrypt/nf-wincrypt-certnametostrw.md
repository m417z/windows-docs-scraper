# CertNameToStrW function

## Description

The **CertNameToStr** function converts an encoded name in a
[CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure to a null-terminated character string.

The string representation follows the distinguished name specifications in [RFC 1779](https://www.ietf.org/rfc/rfc1779.txt). The exceptions to this rule are listed in the Remarks section, below.

## Parameters

### `dwCertEncodingType` [in]

The [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that was used to encode the name. The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) identifier, contained in the high **WORD** of this value, is ignored by this function.

This parameter can be the following currently defined certificate encoding type.

| Value | Meaning |
| --- | --- |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies X.509 certificate encoding. |

### `pName` [in]

A pointer to the
[CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure to be converted.

### `dwStrType` [in]

This parameter specifies the format of the output string. This parameter also specifies other options for the contents of the string.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_SIMPLE_NAME_STR**<br><br>1 | All [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) are discarded. [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) entries are separated by a comma followed by a space (, ). Multiple attributes in a **CERT_RDN** are separated by a plus sign enclosed within spaces ( + ), for example, Microsoft, Kim Abercrombie + Programmer. |
| **CERT_OID_NAME_STR**<br><br>2 | OIDs are included with an equal sign (=) separator from their attribute value. [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) entries are separated by a comma followed by a space (, ). Multiple attributes in a **CERT_RDN** are separated by a plus sign followed by a space (+ ). |
| **CERT_X500_NAME_STR**<br><br>3 | OIDs are converted to their [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) key names; otherwise, they are the same as **CERT_OID_NAME_STR**. If an OID does not have a corresponding X.500 name, the OID is used with a prefix of OID. <br><br> <br><br>The RDN value is quoted if it contains leading or trailing white space or one of the following characters:<br><br>* Comma (,)<br>* Plus sign (+)<br>* Equal sign (=)<br>* Inch mark (")<br>* Backslash followed by the letter n (\n)<br>* Less than sign (<)<br>* Greater than sign (>)<br>* Number sign (#)<br>* Semicolon (;)<br><br>The quotation character is an inch mark ("). If the RDN value contains an inch mark, it is enclosed within quotation marks (""). |

The following options can also be combined with the value above to specify additional options for the string.

| Value | Meaning |
| --- | --- |
| **CERT_NAME_STR_SEMICOLON_FLAG**<br><br>0x40000000 | Replace the comma followed by a space (, ) separator with a semicolon followed by a space (; ) separator. |
| **CERT_NAME_STR_CRLF_FLAG**<br><br>0x08000000 | Replace the comma followed by a space (, ) separator with a backslash followed by the letter r followed by a backslash followed by the letter n (\r\n) separator. |
| **CERT_NAME_STR_NO_PLUS_FLAG**<br><br>0x20000000 | Replace the plus sign enclosed within spaces ( + ) separator with a single space separator. |
| **CERT_NAME_STR_NO_QUOTING_FLAG**<br><br>0x10000000 | Disable quoting. |
| **CERT_NAME_STR_REVERSE_FLAG**<br><br>0x02000000 | The order of the RDNs in the distinguished name string is reversed after decoding. This flag is not set by default. |
| **CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG**<br><br>0x00010000 | By default, a CERT_RDN_T61_STRING X.500 key string is decoded as UTF8. If UTF8 decoding fails, the X.500 key is decoded as an 8 bit character. Use CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG to skip the initial attempt to decode as UTF8. |
| **CERT_NAME_STR_ENABLE_PUNYCODE_FLAG**<br><br>0x00200000 | If the name pointed to by the *pName* parameter contains an email RDN, and the host name portion of the email address contains a Punycode encoded [IA5String](https://learn.microsoft.com/windows/desktop/SecCertEnroll/about-ia5string), the name is converted to the Unicode equivalent.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |

### `psz` [out]

A pointer to a character buffer that receives the returned string. The size of this buffer is specified in the *csz* parameter.

### `csz` [in]

The size, in characters, of the *psz* buffer. The size must include the terminating null character.

## Return value

Returns the number of characters converted, including the terminating null character.

If *psz* is **NULL** or *csz* is zero, returns the required size of the destination string.

## Remarks

If *psz* is not **NULL** and *csz* is not zero, the returned *psz* is always a null-terminated string.

We recommend against using multicomponent RDNs (e.g., CN=James+O=Microsoft) to avoid possible ordering problems when decoding occurs. Instead, consider using single valued RDNs (e.g., CN=James, O=Microsoft).

The string representation follows the distinguished name specifications in [RFC 1779](https://www.ietf.org/rfc/rfc1779.txt) except for the deviations described in the following list.

* Names that contain quotes are enclosed within double quotation marks.
* Empty strings are enclosed within double quotation marks.
* Strings that contain consecutive spaces are not enclosed within quotation marks.
* Relative Distinguished Name (RDN) values of type **CERT_RDN_ENCODED_BLOB** or **CERT_RDN_OCTET_STRING** are formatted in hexadecimal.
* If an OID does not have a corresponding X.500 name, the “OID” prefix is used before OID.
* RDN values are enclosed with double quotation marks (instead of "\") if they contain leading white space, trailing white space, or one of the following characters:
  + Comma (,)
  + Plus sign (+)
  + Equal sign (=)
  + Inch mark (")
  + Backslash (/)
  + Less than sign (<)
  + Greater than sign (>)
  + Number sign (#)
  + Semicolon (;)
* The X.500 key name for stateOrProvinceName (2.5.4.8) OID is "S". This value is different from the RFC 1779 X.500 key name ("ST").

In addition, the following X.500 key names are not mentioned in RFC 1779, but may be returned by this API:

| Key | Object identifier string |
| --- | --- |
| E | 1.2.840.113549.1.9.1 |
| T | 2.5.4.12 |
| G | 2.5.4.42 |
| I | 2.5.4.43 |
| SN | 2.5.4.4 |

#### Examples

For an example that uses this function, see
[Example C Program: Converting Names from Certificates to ASN.1 and Back](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-converting-names-from-certificates-to-asn1-and-back).

> [!NOTE]
> The wincrypt.h header defines CertNameToStr as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CertRDNValueToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certrdnvaluetostra)

[CertStrToName](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certstrtonamea)

[Data Conversion Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)