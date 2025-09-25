# D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_INPUT structure

## Description

Contains input data for a **D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE** command.

## Members

### `Parameters`

A [D3D11_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_input) structure that contains the command GUID and other data.

### `ProcessType`

A [D3D11_AUTHENTICATED_PROCESS_IDENTIFIER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_authenticated_process_identifier_type) value that specifies the type of process.

To specify the Desktop Window Manager (DWM) process, set this member to **D3D11_PROCESSIDTYPE_DWM**. Otherwise, set this member to **D3D11_PROCESSIDTYPE_HANDLE** and set the **ProcessHandle** member to a valid handle.

### `ProcessHandle`

A process handle. If the **ProcessType** member equals **D3D11_PROCESSIDTYPE_HANDLE**, the **ProcessHandle** member specifies a handle to a process. Otherwise, the value is ignored.

### `AllowAccess`

If **TRUE**, the specified process has access to restricted shared resources.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)