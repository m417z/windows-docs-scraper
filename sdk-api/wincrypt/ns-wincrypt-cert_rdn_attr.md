# CERT_RDN_ATTR structure

## Description

The **CERT_RDN_ATTR** structure contains a single attribute of a [relative distinguished name](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RDN). A whole RDN is expressed in a [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structure that contains an array of **CERT_RDN_ATTR** structures.

## Members

### `pszObjId`

[Object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for the type of the attribute defined in this structure. This member can be one of the following OIDs.

| Value | Meaning |
| --- | --- |
| **szOID_AUTHORITY_REVOCATION_LIST** | Security attribute. |
| **szOID_BUSINESS_CATEGORY** | Case-insensitive string. Explanatory attribute. |
| **szOID_CA_CERTIFICATE** | Security attribute. |
| **szOID_CERTIFICATE_REVOCATION_LIST** | Security attribute. |
| **szOID_COMMON_NAME** | Case-insensitive string. Labeling attribute. |
| **szOID_COUNTRY_NAME** | Two-character printable string. Geographic attribute. |
| **szOID_CROSS_CERTIFICATE_PAIR** | Security attribute. |
| **szOID_DESCRIPTION** | Case-insensitive string. Explanatory attribute. |
| **szOID_DESTINATION_INDICATOR** | Printable string. Telecommunications addressing attribute. |
| **szOID_DEVICE_SERIAL_NUMBER** | Printable string. Labeling attribute. |
| **szOID_DOMAIN_COMPONENT** | IA5 string. DNS name component such as "com." |
| **szOID_FACSIMILE_TELEPHONE_NUMBER** | Telecommunications addressing attribute. |
| **szOID_GIVEN_NAME** | Case-insensitive string. Name attribute. |
| **szOID_INITIALS** | Case-insensitive string. Name attribute. |
| **szOID_INTERNATIONAL_ISDN_NUMBER** | Numeric string. Telecommunications addressing attribute. |
| **szOID_LOCALITY_NAME** | Case-insensitive string. Geographic attribute. |
| **szOID_MEMBER** | Relational application attribute. |
| **szOID_ORGANIZATION_NAME** | Case-insensitive string. Organizational attribute. |
| **szOID_ORGANIZATIONAL_UNIT_NAME** | Case-insensitive string. Organizational attribute. |
| **szOID_OWNER** | Relational application attribute. |
| **szOID_PHYSICAL_DELIVERY_OFFICE_NAME** | Case-insensitive string. Postal addressing attribute. |
| **szOID_PKCS_12_FRIENDLY_NAME_ATTR** | PKCS #12 attribute. |
| **szOID_PKCS_12_LOCAL_KEY_ID** | PKCS #12 attribute. |
| **szOID_POST_OFFICE_BOX** | Case-insensitive string. Postal addressing attribute. |
| **szOID_POSTAL_ADDRESS** | Printable string. Postal addressing attribute. |
| **szOID_POSTAL_CODE** | Case-insensitive string. Postal addressing attribute. |
| **szOID_PREFERRED_DELIVERY_METHOD** | Preference attribute. |
| **szOID_PRESENTATION_ADDRESS** | OSI application attribute. |
| **szOID_REGISTERED_ADDRESS** | Telecommunications addressing attribute. |
| **szOID_ROLE_OCCUPANT** | Relational application attribute. |
| **szOID_RSA_emailAddr** | IA5 string. Email attribute. |
| **szOID_SEARCH_GUIDE** | Explanatory attribute. |
| **szOID_SEE_ALSO** | Relational application attribute. |
| **szOID_STATE_OR_PROVINCE_NAME** | Case-insensitive string. Geographic attribute. |
| **szOID_STREET_ADDRESS** | Case-insensitive string. Geographic attribute. |
| **szOID_SUPPORTED_APPLICATION_CONTEXT** | OSI application attribute. |
| **szOID_SUR_NAME** | Case-insensitive string. Labeling attribute. |
| **szOID_TELEPHONE_NUMBER** | Telecommunications addressing attribute. |
| **szOID_TELETEXT_TERMINAL_IDENTIFIER** | Telecommunications addressing attribute. |
| **szOID_TELEX_NUMBER** | Telecommunications addressing attribute. |
| **szOID_TITLE** | Case-insensitive string. Organizational attribute. |
| **szOID_USER_CERTIFICATE** | Security attribute. |
| **szOID_USER_PASSWORD** | Security attribute. |
| **szOID_X21_ADDRESS** | Numeric string. Telecommunications addressing attribute. |

### `dwValueType`

Indicates the interpretation of the **Value** member.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_RDN_ANY_TYPE** | The **pszObjId** member determines the assumed type and length. |
| **CERT_RDN_BMP_STRING** | An array of Unicode characters (16-bit). |
| **CERT_RDN_ENCODED_BLOB** | An encoded data BLOB. |
| **CERT_RDN_GENERAL_STRING** | Currently not used. |
| **CERT_RDN_GRAPHIC_STRING** | Currently not used. |
| **CERT_RDN_IA5_STRING** | An arbitrary string of IA5 ([ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly)) characters. |
| **CERT_RDN_INT4_STRING** | An array of **INT4** elements (32-bit). |
| **CERT_RDN_ISO646_STRING** | A 128-character set (8-bit). |
| **CERT_RDN_NUMERIC_STRING** | Only the characters 0 through 9 and the space character (8-bit). |
| **CERT_RDN_OCTET_STRING** | An arbitrary string of octets (8-bit). |
| **CERT_RDN_PRINTABLE_STRING** | An arbitrary string of printable characters (8-bit). |
| **CERT_RDN_T61_STRING** | An arbitrary string of T.61 characters (8-bit). |
| **CERT_RDN_TELETEX_STRING** | An arbitrary string of T.61 characters (8-bit) |
| **CERT_RDN_UNICODE_STRING** | An array of Unicode characters (16-bit). |
| **CERT_RDN_UNIVERSAL_STRING** | An array of **INT4** elements (32-bit). |
| **CERT_RDN_UTF8_STRING** | An array of 16 bit Unicode characters UTF8 encoded on the wire as a sequence of one, two, or three, eight-bit characters. |
| **CERT_RDN_VIDEOTEX_STRING** | An arbitrary string of videotext characters. |
| **CERT_RDN_VISIBLE_STRING** | A 95-character set (8-bit). |

The following flags can be combined by using a bitwise-**OR** operation into the **dwValueType** member.

| Value | Meaning |
| --- | --- |
| **CERT_RDN_DISABLE_CHECK_TYPE_FLAG** | For encoding. When set, the characters are not checked to determine whether they are valid for the value type. |
| **CERT_RDN_DISABLE_IE4_UTF8_FLAG** | For decoding. By default, **CERT_RDN_T61_STRING** encoded values are initially decoded as UTF8. If the UTF8 decoding fails, the value is decoded as 8-bit characters. If this flag is set, it skips the initial attempt to decode as UTF8 and decodes the value as 8-bit characters. |
| **CERT_RDN_ENABLE_T61_UNICODE_FLAG** | For encoding. When set, if all the Unicode characters are <= 0xFF, the **CERT_RDN_T61_STRING** value is selected instead of the **CERT_RDN_UNICODE_STRING** value. |
| **CERT_RDN_ENABLE_UTF8_UNICODE_FLAG** | For encoding. When set, strings are encoded with the **CERT_RDN_UTF8_STRING** value instead of the **CERT_RDN_UNICODE_STRING** value. |
| **CERT_RDN_FORCE_UTF8_UNICODE_FLAG** | For encoding. When set, strings are encoded with the **CERT_RDN_UTF8_STRING** value instead of **CERT_RDN_PRINTABLE_STRING** value for DirectoryString types. In addition, **CERT_RDN_ENABLE_UTF8_UNICODE_FLAG** is enabled.<br><br>**Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **CERT_RDN_ENABLE_PUNYCODE_FLAG** | For encoding. If the string contains an email RDN, and the email address is Punycode encoded, then the resultant email address is encoded as an **IA5String**. The Punycode encoding of the host name is performed on a label-by-label basis.<br><br>For decoding. If the name contains an email RDN, and the local part or host name portion of the email address contains a Punycode encoded **IA5String**, the RDN string value is converted to its Unicode equivalent.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |

### `Value`

A [CERT_RDN_VALUE_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains the attribute value. The **cbData** member of **Value** is the length, in bytes, of the **pbData** member. It is not the number of elements in the **pbData** string.

For example, a **DWORD** is 32 bits or 4 bytes long. If **pbData** is a **DWORD** array, **cbData** would be four times the number of **DWORD** elements in the array. A **SHORT** is 16 bits or 2 bytes long. If **pbData** is an array of **SHORT** elements, **cbData** must be two times the length of the array.

The **pbData** member of **Value** can be a null-terminated array of 8-bit or 16-bit characters or a fixed-length array of elements. If **dwValueType** is set to CERT_RDN_ENCODED_BLOB, **pbData** is encoded.

## See also

[CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CertIsRDNAttrsInCertificateName](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certisrdnattrsincertificatename)