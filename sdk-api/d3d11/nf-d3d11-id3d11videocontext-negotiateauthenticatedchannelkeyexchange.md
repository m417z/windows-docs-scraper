# ID3D11VideoContext::NegotiateAuthenticatedChannelKeyExchange

## Description

Establishes a session key for an authenticated channel.

## Parameters

### `pChannel` [in]

A pointer to the [ID3D11AuthenticatedChannel](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11authenticatedchannel) interface. This method will fail if the channel type is [D3D11_AUTHENTICATED_CHANNEL_D3D11](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_authenticated_channel_type), because the Direct3D11 channel does not support authentication.

### `DataSize` [in]

The size of the data in the *pData* array, in bytes.

### `pData` [in, out]

A pointer to a byte array that contains the encrypted session key. The buffer must contain 256 bytes of data, encrypted using RSA Encryption Scheme - Optimal Asymmetric Encryption Padding (RSAES-OAEP).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method will fail if the channel type is [D3D11_AUTHENTICATED_CHANNEL_D3D11](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_authenticated_channel_type), because the Direct3D11 channel does not support authentication.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)