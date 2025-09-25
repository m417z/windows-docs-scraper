# IDirect3DAuthenticatedChannel9::NegotiateKeyExchange

## Description

Establishes a session key for the authenticated channel.

## Parameters

### `DataSize`

The size of the data in the *pData* array, in bytes.

### `pData`

A pointer to a byte array that contains the encrypted session key. The buffer must contain 256 bytes of data, encrypted using RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method fails if the channel type is **D3DAUTHENTICATEDCHANNEL_D3D9**, because the Direct3D 9 channel does not support authentication.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DAuthenticatedChannel9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dauthenticatedchannel9)