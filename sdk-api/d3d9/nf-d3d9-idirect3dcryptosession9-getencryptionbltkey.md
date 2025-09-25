# IDirect3DCryptoSession9::GetEncryptionBltKey

## Description

Gets the cryptographic key used to decrypt the data returned by the [IDirect3DCryptoSession9::EncryptionBlt](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-encryptionblt) method.

## Parameters

### `pReadbackKey`

A pointer to a byte array that receives the key. The key is encrypted using the session key.

### `KeySize`

The size of the *pReadbackKey* array, in bytes. The size should match the size of the session key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method applies only when the driver requires a separate content key for the [EncryptionBlt](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-encryptionblt) method. If the driver requires a content key, it sets the **D3DCPCAPS_ENCRYPTEDREADBACKKEY** flag in the capabilities structure returned by the [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) method. Otherwise, the driver uses the session key to encrypt the data.

Each time this method is called, the driver generates a new key.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9)