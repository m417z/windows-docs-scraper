# CRYPT_XML_KEYINFO_PARAM structure

## Description

The **CRYPT_XML_KEYINFO_PARAM** structure is used by the [CryptXmlSign](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlsign) function to specify the members of the **KeyInfo** element to be encoded.

## Members

### `wszId`

A pointer to a null-terminated wide character string that contains the **Id** attribute of the **KeyInfo** element.

### `wszKeyName`

A pointer to a null-terminated wide character string that contains the value in the **KeyName** element.

### `SKI`

A [CERT_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure that contains the value of the **X509SKI** element.

### `wszSubjectName`

A pointer to a null-terminated wide character string that contains the value of the **X509SubjectName** element.

### `cCertificate`

The number of elements in the array pointed to by the **rgCertificate** member.

### `rgCertificate`

A pointer to an array of [CERT_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structures that are used to populate the **X509Certificate** elements.

### `cCRL`

The number of elements in the array pointed to by the **rgCRL** member.

### `rgCRL`

A pointer to an array of [CERT_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structures that are used to populate the **X509CRL** elements.