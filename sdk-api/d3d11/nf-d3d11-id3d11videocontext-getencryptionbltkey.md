# ID3D11VideoContext::GetEncryptionBltKey

## Description

Gets the cryptographic key to decrypt the data returned by the [ID3D11VideoContext::EncryptionBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-encryptionblt) method.

## Parameters

### `pCryptoSession` [in]

A pointer to the [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) interface.

### `KeySize` [in]

The size of the *pReadbackKey* array, in bytes. The size should match the size of the session key.

### `pReadbackKey` [out]

A pointer to a byte array that receives the key. The key is encrypted using the session key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method applies only when the driver requires a separate content key for the [EncryptionBlt](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-encryptionblt) method. For more information, see the Remarks for **EncryptionBlt**.

Each time this method is called, the driver generates a new key.

The *KeySize* should match the size of the session key.

The read back key is encrypted by the driver/hardware using the session key.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)