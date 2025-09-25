# D3D11_1DDI_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_OUTPUT structure

## Description

Contains the response to a [QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel) query with a [D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output).**QueryType** value of **D3D11_1DDI_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS**.

## Members

### `Output`

A structure that contains a Message Authentication Code (MAC) and other data.

### `ProcessIndex`

The index of the process in the list of processes.

### `ProcessIdentifier`

A [D3D11_1DDI_AUTHENTICATED_PROCESS_IDENTIFIER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_process_identifier_type) value that specifies the type of process.

### `ProcessHandle`

A process handle. If the **ProcessIdentifier** member equals **D3D11_1DDI_PROCESSIDTYPE_HANDLE**, the **ProcessHandle** member contains a valid handle to a process. Otherwise, this member is ignored.

## Remarks

The Desktop Window Manager (DWM) process is identified by setting **ProcessIdentifier** equal to **D3D11_1DDI_PROCESSIDTYPE_DWM**. Other processes are identified by setting the process handle in **ProcessHandle** and setting **ProcessIdentifier** equal to **D3D11_1DDI_PROCESSIDTYPE_HANDLE**.

## See also

[D3D11_1DDI_AUTHENTICATED_PROCESS_IDENTIFIER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_authenticated_process_identifier_type)

[D3D11_1DDI_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_authenticated_query_output)

[QueryAuthenticatedChannel(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_queryauthenticatedchannel)