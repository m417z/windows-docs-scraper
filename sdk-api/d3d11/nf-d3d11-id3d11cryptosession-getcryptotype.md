# ID3D11CryptoSession::GetCryptoType

## Description

Gets the type of encryption that is supported by this session.

## Parameters

### `pCryptoType` [out]

Receives a GUID that specifies the encryption type. The following GUIDs are defined.

| Value | Meaning |
| --- | --- |
| **D3D11_CRYPTO_TYPE_AES128_CTR** | 128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher. |

## Remarks

The application specifies the encryption type when it creates the session.

## See also

[ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession)