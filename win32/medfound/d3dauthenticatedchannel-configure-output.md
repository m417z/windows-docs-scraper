# D3DAUTHENTICATEDCHANNEL\_CONFIGURE\_OUTPUT structure

Contains the response to a call to the [**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure) method.

## Members

**omac**

A [**D3D\_OMAC**](https://learn.microsoft.com/windows/win32/medfound/d3d-omac) structure that contains a Message Authentication Code (MAC) of the data. The driver uses AES-based one-key CBC MAC (OMAC) to calculate this value for the block of data that appears after this structure member.

**ConfigureType**

A GUID that specifies the command. For a list of values, see [Content Protection Commands](https://learn.microsoft.com/windows/win32/medfound/content-protection-commands).

**hChannel**

A handle to the authenticated channel.

**SequenceNumber**

The command sequence number.

**ReturnCode**

The result code for the command.

## Remarks

For the **ConfigureType**, **hChannel**, and **SequenceNumber** members, the driver uses the same values that the application provided in the [**D3DAUTHENTICATEDCHANNEL\_CONFIGURE\_INPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-configure-input) structure. The application should verify that these values match.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure)

