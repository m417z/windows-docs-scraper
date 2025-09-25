# D3D11_1DDI_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE structure

## Description

Contains input data for a call to the [ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel) function when [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input).**ConfigureType** has a GUID value of **D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE**.

## Members

### `Parameters`

A [D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input) structure that contains the command GUID and other data.

### `ProcessType`

A [D3D11_1DDI_AUTHENTICATED_PROCESS_IDENTIFIER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_process_identifier_type) value that specifies the type of process. To specify the DWM process, set this member to **D3D11_1DDI_PROCESSIDTYPE_DWM**. Otherwise, set this member to **D3D11_1DDI_PROCESSIDTYPE_HANDLE** and set the **ProcessHandle** member to a valid handle.

### `ProcessHandle`

A process handle. If the **ProcessType** member equals **D3D11_1DDI_PROCESSIDTYPE_HANDLE**, the **ProcessHandle** member specifies a handle to a process. Otherwise, the value is ignored.

### `AllowAccess`

If **TRUE**, the specified process has access to restricted shared resources.

## See also

[ConfigureAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_configureauthenticatedchannel)

[D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_configure_input)

[D3D11_1DDI_AUTHENTICATED_PROCESS_IDENTIFIER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_process_identifier_type)