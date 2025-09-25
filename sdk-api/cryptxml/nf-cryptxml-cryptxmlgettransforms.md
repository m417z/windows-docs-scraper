# CryptXmlGetTransforms function

## Description

The **CryptXmlGetTransforms** function returns information about the default transform chain engine.

## Parameters

### `ppConfig` [out]

A pointer to a pointer to a [CRYPT_XML_TRANSFORM_CHAIN_CONFIG](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_transform_chain_config) structure to receive the returned transform information.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.