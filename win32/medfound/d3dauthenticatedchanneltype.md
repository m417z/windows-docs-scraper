# D3DAUTHENTICATEDCHANNELTYPE enumeration

Specifies the type of Direct3D authenticated channel.

## Constants

**D3DAUTHENTICATEDCHANNEL\_D3D9**

Direct3D 9 channel. This channel provides communication with the Direct3D runtime.

**D3DAUTHENTICATEDCHANNEL\_DRIVER\_SOFTWARE**

Software driver channel. This channel provides communication with a driver that implements content protection mechanisms in software.

**D3DAUTHENTICATEDCHANNEL\_DRIVER\_HARDWARE**

Hardware driver channel. This channel provides communication with a driver that implements content protection mechanisms in the GPU hardware.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h (include D3d9.h) |

## See also

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-enumerations)

[**IDirect3DDevice9Video::CreateAuthenticatedChannel**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-createauthenticatedchannel)

