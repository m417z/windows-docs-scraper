# D3DAUTHENTICATEDCHANNEL\_CONFIGURECRYPTOSESSION structure

Contains input data for a [**D3DAUTHENTICATEDCONFIGURE\_CRYPTOSESSION**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedconfigure-cryptosession) command.

To send this query, call [**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure).

## Members

**Parameters**

A [**D3DAUTHENTICATEDCHANNEL\_CONFIGURE\_INPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-configure-input) structure that contains the command GUID and other data.

**DXVA2DecodeHandle**

A handle to the DirectX Video Acceleration 2 (DXVA-2) decoder device.

**CryptoSessionHandle**

A handle to the cryptographic session.

**DeviceHandle**

A handle to the Direct3D device.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Configure**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-configure)

