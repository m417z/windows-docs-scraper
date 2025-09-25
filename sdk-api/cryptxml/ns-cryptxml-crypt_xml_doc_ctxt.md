# CRYPT_XML_DOC_CTXT structure

## Description

The **CRYPT_XML_DOC_CTXT** structure defines document context information.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hDocCtxt`

The handle of the document context.

### `pTransformsConfig`

A pointer to a [CRYPT_XML_TRANSFORM_CHAIN_CONFIG](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_transform_chain_config) structure that contains information about the transform chain engine.

### `cSignature`

The number of elements in the array pointed to by the **rgpSignature** member.

### `rgpSignature`

A pointer to an array of [CRYPT_XML_SIGNATURE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_signature) structures that contain XML signature information.