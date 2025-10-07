# D3DAUTHENTICATEDCHANNEL\_QUERYCRYPTOSESSION\_OUTPUT structure

Contains the response to a [**D3DAUTHENTICATEDQUERY\_CRYPTOSESSION**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedquery-cryptosession) query.

To send this query, call [**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query).

## Members

**Output**

A [**D3DAUTHENTICATEDCHANNEL\_QUERY\_OUTPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-query-output) structure that contains a Message Authentication Code (MAC) and other data.

**DXVA2DecodeHandle**

A handle to a DirectX Video Acceleration 2 (DXVA-2) decoder device.

**CryptoSessionHandle**

A handle to the cryptographic session that is associated with the decoder device.

**DeviceHandle**

A handle to the Direct3D device that is associated with the decoder device.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query)

