# D3D11_1DDI_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION structure

## Description

Contains input data for a call to the [ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel) function when [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input).**ConfigureType** has a GUID value of **D3D11_1DDI_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE**.

## Members

### `Parameters`

A [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input) structure that contains the command GUID and other data.

### `EncryptionGuid`

A GUID that specifies the type of encryption to apply.

## See also

[ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input)