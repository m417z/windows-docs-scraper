# D3DAUTHENTICATEDCHANNEL\_QUERYCRYPTOSESSION\_INPUT structure

Contains input data for a [**D3DAUTHENTICATEDQUERY\_CRYPTOSESSION**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedquery-cryptosession) query.

To send this query, call [**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query).

## Members

**Input**

A [**D3DAUTHENTICATEDCHANNEL\_QUERY\_INPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-query-input) structure that contains the GUID for the query and other data.

**DXVA2DecodeHandle**

A handle to a DirectX Video Acceleration 2 (DXVA-2) decoder device.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query)

