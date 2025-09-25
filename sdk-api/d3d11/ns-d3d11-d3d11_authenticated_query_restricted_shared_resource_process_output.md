## Description

Contains the response to a **D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS** query.

## Members

### `Output`

A [D3D11_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `ProcessIndex`

The index of the process in the list of processes.

### `ProcessIdentifier`

A [D3D11_AUTHENTICATED_PROCESS_IDENTIFIER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_authenticated_process_identifier_type) value that specifies the type of process.

### `ProcessHandle`

A process handle. If the **ProcessIdentifier** member equals **D3D11_PROCESSIDTYPE_HANDLE**, the **ProcessHandle** member contains a valid handle to a process. Otherwise, this member is ignored.

## Remarks

The Desktop Window Manager (DWM) process is identified by setting **ProcessIdentifier** equal to **D3D11_PROCESSIDTYPE_DWM**. Other processes are identified by setting the process handle in **ProcessHandle** and setting **ProcessIdentifier** equal to **D3D11_PROCESSIDTYPE_HANDLE**.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)