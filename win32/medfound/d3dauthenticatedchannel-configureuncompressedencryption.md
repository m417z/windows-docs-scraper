# D3DAUTHENTICATEDCHANNEL\_CONFIGUREUNCOMPRESSEDENCRYPTION structure

Contains input data for the [**D3DAUTHENTICATEDCONFIGURE\_ENCRYPTIONWHENACCESSIBLE**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedconfigure-encryptionwhenaccessible) command.

To send this query, call [**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure).

## Members

**Parameters**

A [**D3DAUTHENTICATEDCHANNEL\_CONFIGURE\_INPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-configure-input) structure that contains the command GUID and other data.

**EncryptionGuid**

A GUID that specifies the type of encryption to apply.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure)

