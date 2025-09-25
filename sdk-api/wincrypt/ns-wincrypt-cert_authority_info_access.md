# CERT_AUTHORITY_INFO_ACCESS structure

## Description

The **CERT_AUTHORITY_INFO_ACCESS** structure represents authority information access and subject information access certificate extensions and specifies how to access additional information and services for the subject or the issuer of a certificate.

## Members

### `cAccDescr`

The number of elements in the **rgAccDescr** array.

### `rgAccDescr`

An array of pointers to
[CERT_ACCESS_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_access_description) structures that describes the format and location of additional information about the certificate. Each **CERT_ACCESS_DESCRIPTION** structure has as its members a **pszAccessMethod** string that indicates an access method and a
[CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry) structure that indicates the location of the additional information.

## Remarks

The type of information represented by this structure depends on the access methods specified by the [CERT_ACCESS_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_access_description) structures in the *rgAccDescr* array. For more information about access methods, the authority information access extension, and the subject information access extension, see [RFC 3280](https://www.ietf.org/rfc/rfc3280.txt).

The [CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) function creates an instance of this structure when decoding a
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure's **Value** member and the **pszObjId** member of the **CERT_EXTENSION** structure is set to szOID_AUTHORITY_INFO_ACCESS or szOID_SUBJECT_INFO_ACCESS.

An instance of this structure can be used as input to the [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function to create an appropriate [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension).

## See also

[CERT_ACCESS_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_access_description)

[CERT_ALT_NAME_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_entry)

[RFC 3280](https://www.ietf.org/rfc/rfc3280.txt)