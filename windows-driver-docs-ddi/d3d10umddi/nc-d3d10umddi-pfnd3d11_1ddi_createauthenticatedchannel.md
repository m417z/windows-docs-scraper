# PFND3D11_1DDI_CREATEAUTHENTICATEDCHANNEL callback function

## Description

Creates an authenticated channel object. Implemented by a Windows Display Driver Model (WDDM) 1.2 or later user-mode display driver.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `pCreateData`

A pointer to a [D3D11_1DDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createauthenticatedchannel) structure. This structure specifies the attributes of the authenticated channel to be created.

### `hAuthChannel`

A handle to the driver's private data for the authenticated channel object. For more information, see the Remarks section.

### `hRTAuthChannel`

A handle to the authenticated channel object that the driver should use when it calls back into the Direct3D runtime.

## Return value

Returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The authenticated channel was created successfully. |
| **D3DDDIERR_DEVICEREMOVED** | The graphics adapter was removed. |
| **E_OUTOFMEMORY** | Memory was not available to complete the operation. |

## Remarks

The Direct3D runtime calls *CreateAuthenticatedChannel(D3D11_1)* after it has called the driver's [CalcPrivateAuthenticatedChannelSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivateauthenticatedchannelsize) to determine the size in bytes for the private data that the driver requires for the authenticated channel object. The runtime allocates the memory for this private data for the driver. The driver uses this memory to store private data that is related to the authentication channel object.

When the runtime calls *CreateAuthenticatedChannel(D3D11_1)*, it passes the handle to the private data memory in the *hAuthChannel* parameter. This handle is actually a pointer to the memory.

The driver must keep track of the handle to the display device that was used to create the authenticated channel. The driver should fail all subsequent calls that use this created authenticated channel, such as [NegotiateAuthenticatedChannelKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiateauthenticatedchannelkeyexchange), if the display device that is specified in those calls is different from the display device that was used to create the authenticated channel.

## See also

[CalcPrivateAuthenticatedChannelSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivateauthenticatedchannelsize)

[CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel)

[D3D11_1DDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createauthenticatedchannel)

[NegotiateAuthenticatedChannelKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_negotiateauthenticatedchannelkeyexchange)