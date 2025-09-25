# PFND3DDDI_CREATEAUTHENTICATEDCHANNEL callback function

## Description

The **CreateAuthenticatedChannel** function creates a channel that the Microsoft Direct3D runtime and the driver can use to set and query protections.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createauthenicatedchannel) structure. On input, this structure contains information that the driver can use. On output, the driver specifies information in the structure that the Direct3D runtime can use.

## Return value

**CreateAuthenticatedChannel** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The channel is successfully created. |
| **E_OUTOFMEMORY** | [CreateAuthenticatedChannel]() could not allocate the required memory for it to complete. |
| **D3DDDIERR_NOTAVAILABLE** | The driver does not support the channel type that is specified in the ChannelType member of the [D3DDDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createauthenicatedchannel) structure that the pData parameter points to. |

## Remarks

The runtime passes the handle to the authenticated channel that the driver returns in the **ChannelType** member of the [D3DDDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createauthenicatedchannel) structure in all subsequent calls that require the handle.

The driver must keep track of the display device (*hDevice*) that was used to create the authenticated channel. The driver should fail all subsequent calls that use this created authenticated channel (for example, the [AuthenticatedChannelKeyExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_authenticatedchannelkeyexchange) function) if the display device that is specified in those calls is different from the display device that was used to create the authenticated channel.

## See also

[D3DDDIARG_CREATEAUTHENTICATEDCHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createauthenicatedchannel)