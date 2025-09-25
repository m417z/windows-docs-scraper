# D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT structure

## Description

Contains the response to a **D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ATTRIBUTES** query.

## Members

### `Output`

A [D3D11_AUTHENTICATED_QUERY_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output) structure that contains a Message Authentication Code (MAC) and other data.

### `BusType`

A bitwise **OR** of flags from the [D3D11_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bus_type) enumeration.

### `AccessibleInContiguousBlocks`

If **TRUE**, contiguous blocks of video memory may be accessible to the CPU or the bus.

### `AccessibleInNonContiguousBlocks`

If **TRUE**, non-contiguous blocks of video memory may be accessible to the CPU or the bus.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)