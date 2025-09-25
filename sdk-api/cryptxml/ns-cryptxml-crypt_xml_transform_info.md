# CRYPT_XML_TRANSFORM_INFO structure

## Description

The **CRYPT_XML_TRANSFORM_INFO** structure contains information that is used when applying the data transform.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `wszAlgorithm`

A pointer to a null-terminated Unicode string that contains the **Algorithm** attribute.

### `cbBufferSize`

The size, in bytes, of the data provider's buffer. The size can be zero if the size cannot be determined at initialization time.
This value is used by a caller of the structure pointed to by the **pfnCreateTransform** member to determine the necessary size of the receiving buffer.

### `dwFlags`

Specifies values that control how the transform is applied.

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_TRANSFORM_ON_STREAM**<br><br>0x00000001 | Specifies that the input to the transform is a stream of bytes. |
| **CRYPT_XML_TRANSFORM_ON_NODESET**<br><br>0x00000002 | Specifies that the input to the transform is an XML node set. |
| **CRYPT_XML_TRANSFORM_URI_QUERY_STRING**<br><br>0x00000003 | Specifies that the URI comparison is to be performed on the core URI without the QueryString.<br><br>In some cases, the URI may contain additional information in the QueryString after the ampersand (&). Use this flag to evaluate only the core URI. |

### `pfnCreateTransform`

A pointer to a [PFN_CRYPT_XML_CREATE_TRANSFORM](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-pfn_crypt_xml_create_transform) callback function used to create the transform.

## Remarks

For XML canonicalization transforms, the buffer size specified by the **cbBufferSize** member must be large enough to accommodate an entire **Start** element with all attribute values.

## See also

[Digital Signature Cryptographic Algorithms](https://learn.microsoft.com/windows/desktop/SecCrypto/xml-digital-signature-cryptographic-algorithms)