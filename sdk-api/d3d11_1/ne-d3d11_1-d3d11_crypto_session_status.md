# D3D11_CRYPTO_SESSION_STATUS enumeration

## Description

Represents the status of an [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) interface.

## Constants

### `D3D11_CRYPTO_SESSION_STATUS_OK:0`

The [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) is in a functional state.

### `D3D11_CRYPTO_SESSION_STATUS_KEY_LOST:1`

The underlying hardware key for the specified [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) has become lost.

### `D3D11_CRYPTO_SESSION_STATUS_KEY_AND_CONTENT_LOST:2`

The underlying hardware key for the specified [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) has become lost and protected content has become corrupted.

## See also

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)