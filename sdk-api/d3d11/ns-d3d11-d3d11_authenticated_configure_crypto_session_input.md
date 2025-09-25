# D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT structure

## Description

Contains input data for a **D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION** command.

## Members

### `Parameters`

A [D3D11_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_input) structure that contains the command GUID and other data.

### `DecoderHandle`

A handle to the decoder device. Get this from [ID3D11VideoDecoder::GetDriverHandle](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodecoder-getdriverhandle).

### `CryptoSessionHandle`

A handle to the cryptographic session. Get this from [ID3D11CryptoSession::GetCryptoSessionHandle](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11cryptosession-getcryptosessionhandle).

### `DeviceHandle`

A handle to the Direct3D device. Get this from [D3D11VideoContext::QueryAuthenticatedChannel](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-queryauthenticatedchannel) using **D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE**.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)