# D3DAUTHENTICATEDCHANNEL\_CONFIGURESHAREDRESOURCE structure

Contains input data for a [**D3DAUTHENTICATEDCONFIGURE\_SHAREDRESOURCE**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedconfigure-sharedresource) command.

To send this query, call [**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure).

## Members

**Parameters**

A [**D3DAUTHENTICATEDCHANNEL\_CONFIGURE\_INPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-configure-input) structure that contains the command GUID and other data.

**ProcessIdentiferType**

A [**D3DAUTHENTICATEDCHANNEL\_PROCESSIDENTIFIERTYPE**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-processidentifiertype) value that specifies the type of process. To specify the Desktop Window Manager (DWM) process, set this member to **PROCESSIDTYPE\_DWM**. Otherwise, set this member to **PROCESSIDTYPE\_HANDLE** and set the **ProcessHandle** member to a valid handle.

**ProcessHandle**

A process handle. If the **ProcessIdentifier** member equals **PROCESSTIDTYPE\_HANDLE**, the **ProcessHandle** member specifies a handle to a process. Otherwise, the value is ignored.

**AllowAccess**

If **TRUE**, the specified process has access to restricted shared resources.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure)

