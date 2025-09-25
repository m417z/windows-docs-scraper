# PFND3D11_1DDI_CONFIGUREAUTHENTICATEDCHANNEL callback function

## Description

Processes a request from an application to configure an authenticated channel for content protection. Implemented by a Windows Display Driver Model (WDDM) 1.2 or later user-mode display driver.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hCAuthChannel`

A handle to the authenticated channel object that was created through a call to the [CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel) function.

### `InputDataSize`

The size, in bytes, of the array that is specified by the *pInputData* parameter.

### `pInputData`

A pointer to a byte array that contains input data for the command. For more information, see the Remarks section.

### `pOutputData`

A pointer to a [D3D11_1DDI_AUTHENTICATED_CONFIGURE_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_output) structure. For more information, see the Remarks section.

## Return value

Returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The authenticated channel was configured successfully. |
| **E_FAIL** | The display miniport driver does not support the specified command |
| **E_INVALIDARG** | Parameters were validated and determined to be incorrect. |
| **E_OUTOFMEMORY** | Memory was not available to complete the operation. |

## Remarks

The byte array that is referenced by the *pInputData* parameter is formatted in the following way:

* This array starts with a [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input) structure.

* The data that follows this structure is in a format that is specified by the **ConfigureType** member of the structure.

The following list describes the format of this data based on the **ConfigureType** member.

* **D3D11_1DDI_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_GUID**
[D3D11_1DDI_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_crypto_session)

* **D3D11_1DDI_AUTHENTICATED_CONFIGURE_ENCRYPTION_WHEN_ACCESSIBLE_GUID**
[D3D11_1DDI_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_accessible_encryption)

* **D3D11_1DDI_AUTHENTICATED_CONFIGURE_INITIALIZE_GUID**
[D3D11_1DDI_AUTHENTICATED_CONFIGURE_INITIALIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_initialize)

* **D3D11_1DDI_AUTHENTICATED_CONFIGURE_PROTECTION_GUID**
[D3D11_1DDI_AUTHENTICATED_CONFIGURE_PROTECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_protection)

* **D3D11_1DDI_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_GUID**
[D3D11_1DDI_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_shared_resource)

The [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input) structure contains an AES-based one-key CBC message authentication code (OMAC) of the data. The display miniport driver must calculate its own OMAC over the data to authenticate the data. This input structure also contains a driver handle to the authenticated channel, a sequence number, and a GUID that indicates the configuration type.

The display miniport driver follows these steps when it initializes the [D3D11_1DDI_AUTHENTICATED_CONFIGURE_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_output) structure:

1. The driver must copy the input data to the [D3D11_1DDI_AUTHENTICATED_CONFIGURE_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_output) structure.

2. The driver must set the ReturnCode member to the same return code that it will return for the ConfigureAuthenticatedChannel(D3D11_1) call. This provides the application with a secure mechanism of accessing the return code.

3. The driver sets the omac member to zero and then calculates an OMAC for the data in the structure. The driver then sets the omac member to the OMAC that it calculated

The display miniport driver must return **E_INVALIDARG** for the **ConfigureAuthenticatedChannel** call under the following conditions:

* The omac member of the[D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input) structure does not match the OMAC that the driver calculated.

* The sequence number is not greater than a sequence number that was specified in a previous configuration call.

* The sequence number has not yet been initialized by a call to the ConfigureAuthenticatedChannel(D3D11_1) function.

* The InputDataSize parameter is less than the size of the [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input) structure plus the size of the structure specified by the D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT.ConfigureTypemember.

## See also

[CreateAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createauthenticatedchannel)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_output)