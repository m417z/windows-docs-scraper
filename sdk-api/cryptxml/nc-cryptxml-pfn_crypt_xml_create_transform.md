# PFN_CRYPT_XML_CREATE_TRANSFORM callback function

## Description

The *PFN_CRYPT_XML_CREATE_TRANSFORM* callback function creates a transform for a specified data provider.

## Parameters

### `pTransform` [in]

A [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the transform to apply.

### `pProviderIn` [in]

A pointer to a [CRYPT_XML_DATA_PROVIDER](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_data_provider) structure that specifies the data provider to use as input for the transform.

### `pProviderOut` [out]

A pointer to a [CRYPT_XML_DATA_PROVIDER](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_data_provider) structure to receive the data provider of the transform.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.

## Remarks

In the transform chain, the output of a transform is the input of the next transform in the chain.

 The implementation of the callback function is responsible for calling the provider close function on the input transform to release the input provider.