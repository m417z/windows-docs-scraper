# CRYPT_XML_STATUS structure

## Description

The **CRYPT_XML_STATUS** structure returns information about the signature validation status,
summary status information about a **SignedInfo** element, or summary status information
about an array of **Reference** elements. The **CRYPT_XML_STATUS** structure is used by the [CryptXmlGetStatus](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlgetstatus) function.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwErrorStatus`

The retrieved error flags.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_STATUS_ERROR_NOT_RESOLVED**<br><br>0x00000001 | One of the references could not be resolved. |
| **CRYPT_XML_STATUS_ERROR_DIGEST_INVALID**<br><br>0x0000002 | The digest value could not be verified. |
| **CRYPT_XML_STATUS_ERROR_NOT_SUPPORTED_ALGORITHM**<br><br>0x00000005 | One of the algorithm URIs specified in XML is not supported. |
| **CRYPT_XML_STATUS_ERROR_NOT_SUPPORTED_TRANSFORM**<br><br>0x00000008 | One of the transform URIs specified in XML is not supported. |
| **CRYPT_XML_STATUS_ERROR_SIGNATURE_INVALID**<br><br>0x00010000 | The signature value could not be verified. |
| **CRYPT_XML_STATUS_ERROR_KEYINFO_NOT_PARSED**<br><br>0x00020000 | Unable to parse the **KeyInfo** element. |

### `dwInfoStatus`

The retrieved informational flags.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_STATUS_INTERNAL_REFERENCE**<br><br>0x00000001 | The reference URI points to an internal element in XML and can be resolved automatically. |
| **CRYPT_XML_STATUS_KEY_AVAILABLE**<br><br>0x00000002 | The **KeyValue** element parsed, and a key handle imported successfully. |
| **CRYPT_XML_STATUS_DIGESTING**<br><br>0x00000004 | The reference is being added to the digest. |
| **CRYPT_XML_STATUS_DIGEST_VALID**<br><br>0x00000008 | The digest value was verified. |
| **CRYPT_XML_STATUS_SIGNATURE_VALID**<br><br>0x00010000 | The signature value was verified. |
| **CRYPT_XML_STATUS_OPENED_TO_ENCODE**<br><br>0x80000000 | The document is open for encoding. |