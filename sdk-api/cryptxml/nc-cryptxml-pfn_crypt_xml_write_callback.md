# PFN_CRYPT_XML_WRITE_CALLBACK callback function

## Description

The *PFN_CRYPT_XML_WRITE_CALLBACK* callback function writes XML data.

## Parameters

### `pvCallbackState` [in, out]

A pointer to an argument that is passed to the callback function pointed to by the *pfnWrite* parameter of the [CryptXmlDllEncodeAlgorithm](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllencodealgorithm) function.

### `pbData` [in]

A pointer to a block of data to be written.

### `cbData`

The size, in bytes, of the data pointed to by the *pbData* parameter.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.