# D3DAUTHENTICATEDCHANNEL\_CONFIGURE\_INPUT structure

Contains input data for the [**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure) method.

## Members

**omac**

A [**D3D\_OMAC**](https://learn.microsoft.com/windows/win32/medfound/d3d-omac) structure that contains a Message Authentication Code (MAC) of the data. The driver uses AES-based one-key CBC MAC (OMAC) to calculate this value for the block of data that appears after this structure member.

**ConfigureType**

A GUID that specifies the command. For a list of values, see [Content Protection Commands](https://learn.microsoft.com/windows/win32/medfound/content-protection-commands).

**hChannel**

A handle to the authenticated channel. To get the handle, call [**IDirect3DDevice9Video::CreateAuthenticatedChannel**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-createauthenticatedchannel).

**SequenceNumber**

The query sequence number. At the start of the session, generate a cryptographically secure 32-bit random number to use as the starting sequence number. For each command, increment the sequence number by 1.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure)

