## Description

The **CryptXmlDllDigestData** function puts data into the digest.

The **CryptXmlDllDigestData** function is exposed through the exported [CryptXmlDllGetInterface](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetinterface) function.

## Parameters

### `hDigest`

The handle of the hash object used to put data into the digest. This handle is obtained by calling the [CryptXmlDllCreateDigest](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllcreatedigest) function.

### `pbData`

A pointer to a block of data to be processed.

### `cbData`

The size, in bytes, of the block of data pointed to by the *pbData* parameter.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.