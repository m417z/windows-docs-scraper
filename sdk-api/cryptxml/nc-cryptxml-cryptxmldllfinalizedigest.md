# CryptXmlDllFinalizeDigest callback function

## Description

The **CryptXmlDllFinalizeDigest** function retrieves the digest value.

The **CryptXmlDllFinalizeDigest** function is exposed through the exported [CryptXmlDllGetInterface](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetinterface) function.

## Parameters

### `hDigest` [in]

The handle of the hash object used to put data into the digest. This handle is obtained by calling the [CryptXmlDllCreateDigest](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllcreatedigest) function.

### `pbDigest` [out]

A pointer to a buffer that receives the digest value.

### `cbDigest`

The size, in bytes, of the buffer pointed to by the *pbDigest* parameter.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.