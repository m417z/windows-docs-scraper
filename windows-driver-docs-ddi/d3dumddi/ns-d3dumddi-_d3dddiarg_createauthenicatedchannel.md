# _D3DDDIARG_CREATEAUTHENICATEDCHANNEL structure

## Description

The D3DDDIARG_CREATEAUTHENTICATEDCHANNEL structure identifies a channel to create.

## Members

### `ChannelType` [in]

A [DDIAUTHENTICATEDCHANNELTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_ddiauthenticatedchanneltype)-typed value that indicates the channel type to create. This member can be one of the following values.

| **Value** | **Meaning** |
|:--|:--|
| DDIAUTHENTICATEDCHANNEL_DRIVER_SOFTWARE (2) | The authenticated-channel type is software. |
| DDIAUTHENTICATEDCHANNEL_DRIVER_HARDWARE (3) | The authenticated-channel type is hardware. |

### `hChannel` [out]

A handle to the channel. The user-mode display driver's [CreateAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createauthenticatedchannel) function returns this handle to the Microsoft Direct3D runtime.

## See also

[CreateAuthenticatedChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createauthenticatedchannel)

[DDIAUTHENTICATEDCHANNELTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_ddiauthenticatedchanneltype)