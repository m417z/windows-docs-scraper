# CRYPT_XML_ALGORITHM structure

## Description

The **CRYPT_XML_ALGORITHM** structure specifies the algorithm used to sign or transform the message.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `wszAlgorithm`

A pointer to a null-terminated Unicode string that contains the **Algorithm** attribute.
When the **Encoded** member contains an element that is proved by an application, this member is set to **NULL**.XML

### `Encoded`

Optional. The XML encoded element.
This member is set when an element tag is present in the XML signature.

## See also

[Digital Signature Cryptographic Algorithms](https://learn.microsoft.com/windows/desktop/SecCrypto/xml-digital-signature-cryptographic-algorithms)