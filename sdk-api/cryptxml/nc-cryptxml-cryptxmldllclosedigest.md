# CryptXmlDllCloseDigest callback function

## Description

The **CryptXmlDllCloseDigest** function frees the CRYPT_XML_DIGEST allocated by the [CryptXmlDllCreateDigest](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllcreatedigest) function.

The *CryptXmlDllCloseDigest* function is exposed through the Cryptographic Extensions DLL and is exposed through the exported [CryptXmlDllGetInterface](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetinterface) function.

## Parameters

### `hDigest` [in]

The handle of the hash object. This handle is obtained by calling the [CryptXmlCreateDigest](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllcreatedigest) function. After the function has been called, the digest handle passed to this function is released and cannot be used again.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.