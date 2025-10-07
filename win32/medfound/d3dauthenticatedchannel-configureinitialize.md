# D3DAUTHENTICATEDCHANNEL\_CONFIGUREINITIALIZE structure

Contains input data for a [**D3DAUTHENTICATEDCONFIGURE\_INITIALIZE**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedconfigure-initialize) command.

To send this query, call [**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure).

## Members

**Parameters**

A [**D3DAUTHENTICATEDCHANNEL\_CONFIGURE\_INPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-configure-input) structure that contains the command GUID and other data.

**StartSequenceQuery**

The initial sequence number for queries.

**StartSequenceConfigure**

The initial sequence number for commands.

## Remarks

The **StartSequenceQuery** and **StartSequenceConfigure** members each contain a cryptographically secure 32-bit random number.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure)

