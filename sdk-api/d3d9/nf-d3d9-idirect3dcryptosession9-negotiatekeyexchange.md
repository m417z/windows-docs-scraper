# IDirect3DCryptoSession9::NegotiateKeyExchange

## Description

Establishes the session key for the cryptographic session.

## Parameters

### `DataSize`

The size of the *pData* byte array, in bytes.

### `pData`

A pointer to a byte array that contains the encrypted session key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To find out which key-exchange mechanism to use, call the [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) method. The key-exchange mechanism is specified in the **KeyExchangeType** member of the [D3DCONTENTPROTECTIONCAPS](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcontentprotectioncaps) structure. If the value is **D3DKEYEXCHANGE_RSAES_OAEP**, use RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP) to encrypt the session key. Pass this encrypted cyphertext in the *pData* parameter.

If the key-exchange type is **D3DKEYEXCHANGE_DXVA**, do not call this method to establish the session key. Instead, use the key-exchange mechanism that is defined for DirectX Video Acceleration 2 (DXVA-2) decoding.

The driver might also use a proprietary key-exchange mechanism.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9)