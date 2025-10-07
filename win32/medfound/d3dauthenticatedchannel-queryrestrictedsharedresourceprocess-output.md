# D3DAUTHENTICATEDCHANNEL\_QUERYRESTRICTEDSHAREDRESOURCEPROCESS\_OUTPUT structure

Contains the response to a [**D3DAUTHENTICATEDQUERY\_RESTRICTEDSHAREDRESOURCEPROCESS**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedquery-restrictedsharedresourceprocess) query.

To send this query, call [**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query).

## Members

**Output**

A [**D3DAUTHENTICATEDCHANNEL\_QUERY\_OUTPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-query-output) structure that contains a Message Authentication Code (MAC) and other data.

**ProcessIndex**

The index of the process in the list of processes.

**ProcessIdentifer**

A [**D3DAUTHENTICATEDCHANNEL\_PROCESSIDENTIFIERTYPE**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-processidentifiertype) value that specifies the type of process.

**ProcessHandle**

A process handle. If the **ProcessIdentifier** member equals **PROCESSIDTYPE\_HANDLE**, the **ProcessHandle** member contains a valid handle to a process. Otherwise, this member is ignored.

## Remarks

The Desktop Window Manager (DWM) process is identified by setting **ProcessIdentifier** equal to **PROCESSIDTYPE\_DWM**. Other processes are identified by setting the process handle in **ProcessHandle** and setting **ProcessIdentifier** equal to **PROCESSIDTYPE\_HANDLE**.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query)

