# ID3D11VideoDevice::CreateCryptoSession

## Description

Creates a cryptographic session to encrypt video content that is sent to the graphics driver.

## Parameters

### `pCryptoType` [in]

A pointer to a GUID that specifies the type of encryption to use. The following GUIDs are defined.

| Value | Meaning |
| --- | --- |
| **D3D11_CRYPTO_TYPE_AES128_CTR** | 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher. |

### `pDecoderProfile` [in]

A pointer to a GUID that specifies the decoding profile. For a list of possible values, see [ID3D11VideoDevice::GetVideoDecoderProfile](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getvideodecoderprofile). If decoding will not be used, set this parameter to **NULL**.

### `pKeyExchangeType` [in]

A pointer to a GUID that specifies the type of key exchange.

| Value | Meaning |
| --- | --- |
| **D3D11_KEY_EXCHANGE_RSAES_OAEP** | The caller will create the session key, encrypt it with RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP) by using the driver's public key, and pass the session key to the driver. |

### `ppCryptoSession` [out]

Receives a pointer to the [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [ID3D11DeviceContext::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate) method does not affect the internal state of the cryptographic session.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)