## Description

The **CryptXmlDllVerifySignature** function verifies a signature.

The **CryptXmlDllVerifySignature** function is exposed through the exported [CryptXmlDllGetInterface](https://learn.microsoft.com/windows/desktop/api/cryptxml/nc-cryptxml-cryptxmldllgetinterface) function.

## Parameters

### `pSignatureMethod` [in]

A pointer to a [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the algorithm.

### `hKey` [in]

A handle to the public key.

### `pbInput` [in]

A pointer to a buffer that contains the signed data. The *cbInput* parameter contains the size of this buffer.

### `cbInput` [in]

The size, in bytes, of the buffer pointed to by the *pbInput* parameter.

### `pbSignature` [in]

A pointer to a buffer that contains the signature value to be verified. The *cbSignature* parameter contains the size of this buffer.

### `cbSignature` [in]

The size, in bytes, of the *pbSignature* buffer.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.