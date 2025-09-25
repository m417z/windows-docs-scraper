# CERT_ALT_NAME_ENTRY structure

## Description

The **CERT_ALT_NAME_ENTRY** structure contains an alternative name in one of a variety of name forms. These names are bound by a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) to a certificate's public key.

A structure can be **CERT_ALT_NAME_ENTRY** member of a
[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) structure.

## Members

### `dwAltNameChoice`

Indicates the **union** variant used for the alternative name.

This can be one of the following values:

* CERT_ALT_NAME_OTHER_NAME
* CERT_ALT_NAME_RFC822_NAME
* CERT_ALT_NAME_DNS_NAME
* CERT_ALT_NAME_DIRECTORY_NAME
* CERT_ALT_NAME_URL
* CERT_ALT_NAME_IP_ADDRESS
* CERT_ALT_NAME_REGISTERED_ID

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.pOtherName`

A pointer to a **CERT_OTHER_NAME** structure, which includes an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and a [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) containing the name.

### `DUMMYUNIONNAME.pwszRfc822Name`

Email address as a Unicode string.

### `DUMMYUNIONNAME.pwszDNSName`

DNS name as an IA5 string.

### `DUMMYUNIONNAME.DirectoryName`

A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) structure that contains a directory name.

### `DUMMYUNIONNAME.pwszURL`

URL as a IA5 string.

### `DUMMYUNIONNAME.IPAddress`

Octet string that is an Internet Protocol address defined in accordance with Internet [RFC 791](https://www.ietf.org/rfc/rfc791.txt).

### `DUMMYUNIONNAME.pszRegisteredID`

Object identifier (OID) of any registered object.

## See also

[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info)

[CRYPT_ATTRIBUTE_TYPE_VALUE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute_type_value)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))