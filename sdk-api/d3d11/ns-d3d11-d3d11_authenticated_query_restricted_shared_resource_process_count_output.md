# D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT structure

## Description

Contains the response to a **D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT** query.

## Members

### `Output`

A [D3D11_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `RestrictedSharedResourceProcessCount`

The number of processes that are allowed to open shared resources that have restricted access. A process cannot open such a resource unless the process has been granted access.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)