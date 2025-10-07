# D3DAUTHENTICATEDCHANNEL\_QUERYRESTRICTEDSHAREDRESOURCEPROCESS\_INPUT structure

Contains input data for a [**D3DAUTHENTICATEDQUERY\_RESTRICTEDSHAREDRESOURCEPROCESS**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedquery-restrictedsharedresourceprocess) query.

To send this query, call [**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query).

## Members

**Input**

A [**D3DAUTHENTICATEDCHANNEL\_QUERY\_INPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-query-input) structure that contains the GUID for the query and other data.

**ProcessIndex**

The index of the process.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query)

