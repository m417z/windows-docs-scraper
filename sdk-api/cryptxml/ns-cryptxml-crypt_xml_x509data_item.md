# CRYPT_XML_X509DATA_ITEM structure

## Description

The **CRYPT_XML_X509DATA_ITEM** structure represents [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) data that is to be encoded in an X509Data named element.

## Members

### `dwType`

Specifies the data item type.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_X509DATA_TYPE_ISSUER_SERIAL**<br><br>0x00000001 | The X.509 data is an issuer serial number. |
| **CRYPT_XML_X509DATA_TYPE_SKI**<br><br>0x00000002 | The X.509 data is a Subject Key Identifier (SKI). |
| **CRYPT_XML_X509DATA_TYPE_SUBJECT_NAME**<br><br>0x00000003 | The X.509 data is a subject name. |
| **CRYPT_XML_X509DATA_TYPE_CERTIFICATE**<br><br>0x00000004 | The X.509 data is a certificate. |
| **CRYPT_XML_X509DATA_TYPE_CRL**<br><br>0x00000005 | The X.509 data is a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL). |
| **CRYPT_XML_X509DATA_TYPE_CUSTOM**<br><br>0x00000006 | The X.509 data is a custom format. |

### `IssuerSerial`

A [CRYPT_XML_ISSUER_SERIAL](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_issuer_serial) structure that contains serial number data.

### `SKI`

A [CRYPT_XML_DATA_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_data_blob) structure that contains SKI data.

### `wszSubjectName`

A pointer to a null-terminated Unicode string that contains the subject name.

### `Certificate`

A [CRYPT_XML_DATA_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_data_blob) structure that contains certificate data.

### `CRL`

A [CRYPT_XML_DATA_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_data_blob) that contains a CRL.

### `Custom`

A [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains custom data.