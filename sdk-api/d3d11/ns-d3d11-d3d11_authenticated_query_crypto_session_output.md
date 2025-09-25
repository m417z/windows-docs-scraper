## Description

Contains the response to a **D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION** query.

## Members

### `Output`

A [D3D11_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `DecoderHandle`

A handle to a decoder device.

### `CryptoSessionHandle`

A handle to the cryptographic session that is associated with the decoder device.

### `DeviceHandle`

A handle to the Direct3D device that is associated with the decoder device.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)