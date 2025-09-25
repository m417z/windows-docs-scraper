# D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT_OUTPUT structure

## Description

Contains the response to a **D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT** query.

## Members

### `Output`

A [D3D11_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `UnrestrictedProtectedSharedResourceCount`

The number of protected, shared resources that can be opened by any process without restrictions.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)