# ID3D11VideoDevice::CreateAuthenticatedChannel

## Description

Creates a channel to communicate with the Microsoft Direct3D device or the graphics driver. The channel can be used to send commands and queries for content protection.

## Parameters

### `ChannelType` [in]

Specifies the type of channel, as a member of the [D3D11_AUTHENTICATED_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_authenticated_channel_type) enumeration.

### `ppAuthenticatedChannel` [out]

Receives a pointer to the [ID3D11AuthenticatedChannel](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11authenticatedchannel) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the *ChannelType* parameter is **D3D11_AUTHENTICATED_CHANNEL_D3D11**, the method creates a channel with the Direct3D device. This type of channel does not support authentication.

If *ChannelType* is **D3D11_AUTHENTICATED_CHANNEL_DRIVER_SOFTWARE** or **D3D11_AUTHENTICATED_CHANNEL_DRIVER_HARDWARE**, the method creates an authenticated channel with the graphics driver.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)