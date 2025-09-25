# D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT structure

## Description

Contains the response to a **D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT** query.

## Members

### `Output`

A [D3D11_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `DeviceHandle`

A handle to the device.

### `CryptoSessionHandle`

A handle to the cryptographic session.

### `OutputIDCount`

The number of output IDs associated with the specified device and cryptographic session.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)