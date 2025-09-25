# CryptXmlDllCreateDigest callback function

## Description

The **CryptXmlDllCreateDigest** function creates a digest object for the specified method.

The **CryptXmlDllCreateDigest** function is exposed through the exported [CryptXmlDllGetInterface](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetinterface) function.

## Parameters

### `pDigestMethod` [in]

A pointer to a [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the algorithm to use to create the digest.

### `pcbSize` [out]

A pointer to a **ULONG** variable that receives the size, in bytes, of the digest.

### `phDigest` [out]

A pointer to a **CRYPT_XML_DIGEST** variable that receives a pointer to the digest.

When you have finished using the resources allocated by the call to this function, you must free them by calling the [CryptXmlDllCloseDigest](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllclosedigest) function.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.