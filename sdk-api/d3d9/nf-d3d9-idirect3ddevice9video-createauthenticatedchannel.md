# IDirect3DDevice9Video::CreateAuthenticatedChannel

## Description

Creates a channel to communicate with the Direct3D device or the graphics driver.

## Parameters

### `ChannelType`

Specifies the type of channel, as a member of the [D3DAUTHENTICATEDCHANNELTYPE](https://learn.microsoft.com/windows/desktop/medfound/d3dauthenticatedchanneltype) enumeration.

### `ppAuthenticatedChannel`

Receives a pointer to the [IDirect3DAuthenticatedChannel9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dauthenticatedchannel9) interface. The caller must release the interface.

### `pChannelHandle`

Receives a pointer to a handle for the channel.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the *ChannelType* parameter is **D3DAUTHENTICATEDCHANNEL_D3D9**, the method creates a channel with the Direct3D device. This type of channel does not support authentication.

If *ChannelType* is **D3DAUTHENTICATEDCHANNEL_DRIVER_SOFTWARE** or **D3DAUTHENTICATEDCHANNEL_DRIVER_HARDWARE**, the method creates an authenticated channel with the graphics driver.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DDevice9Video](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9video)