# ID3D11VideoContext::NegotiateCryptoSessionKeyExchange

## Description

Establishes the session key for a cryptographic session.

## Parameters

### `pCryptoSession` [in]

A pointer to the [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) interface of the cryptographic session.

### `DataSize` [in]

The size of the *pData* byte array, in bytes.

### `pData` [in, out]

A pointer to a byte array that contains the encrypted session key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The key exchange mechanism depends on the type of cryptographic session.

For RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP), the software decoder generates the secret key, encrypts the secret key by using the public key with RSAES-OAEP, and places the cipher text in the *pData* parameter. The actual size of the buffer for RSAES-OAEP is 256 bytes.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)