# ID3D11CryptoSession::GetCryptoSessionHandle

## Description

Gets a handle to the cryptographic session.

## Parameters

### `pCryptoSessionHandle` [out]

Receives a handle to the session.

## Remarks

You can use this handle to associate the session with a decoder. This enables the decoder to decrypt data that is encrypted using this session.

## See also

[ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession)