# D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT structure

## Description

Contains input data for the [ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel) function.

## Members

### `omac`

A [D3D11_1DDI_OMAC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_omac) structure that contains a Message Authentication Code (MAC) of the data. The driver uses Advanced Encryption Standard (AES)-based one-key CBC MAC (OMAC) to calculate this value for the block of data that appears after this structure member.

### `ConfigureType`

A GUID that specifies the command. The following GUIDs are defined.

#### D3D11_1DDI_AUTHENTICATED_CONFIGURE_ENCRYPTION_WHEN_ACCESSIBLE_GUID

Sets the level of encryption that is performed before protected content becomes accessible to the CPU or bus.

Input data: [D3D11_1DDI_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_accessible_encryption)

#### D3D11_1DDI_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_GUID

Associates a cryptographic session with a DirectX Video Acceleration 2 (DXVA-2) decode device and a Direct3D device.

Input data: [D3D11_1DDI_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_crypto_session)

#### D3D11_1DDI_AUTHENTICATED_CONFIGURE_INITIALIZE_GUID

Initializes the authenticated channel.

Input data: [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INITIALIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_initialize)

#### D3D11_1DDI_AUTHENTICATED_CONFIGURE_PROTECTION_GUID

Enables or disables protection for the device.

Input data: [D3D11_1DDI_AUTHENTICATED_CONFIGURE_PROTECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_protection)

#### D3D11_1DDI_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_GUID

Enables a process to open a shared resource, or disables a process from opening shared resources.

Input data: [D3D11_1DDI_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_shared_resource)

### `hChannel`

A handle to the authenticated channel. This handle was created through a call to the [CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel) function.

### `SequenceNumber`

The query sequence number.

**Note** The sequence number must increase with each successive call to the [ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel) function.

## Remarks

For information on the usage of this structure, see the Remarks of the [ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel) function.

## See also

[ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel)

[CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_accessible_encryption)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_crypto_session)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_INITIALIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_initialize)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_PROTECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_protection)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_shared_resource)

[D3D11_1DDI_OMAC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_omac)