# D3D11_1DDI_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION structure

## Description

Contains input data for a call to the [ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel) function when [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input).**ConfigureType** has a GUID value of **D3D11_1DDI_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION**.

## Members

### `Parameters`

A [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input) structure that contains the command GUID and other data.

### `DecodeHandle`

A handle to the decoder device.

### `CryptoSessionHandle`

A handle to the cryptographic session.

### `DeviceHandle`

A handle to the Direct3D device.

## See also

[ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input)