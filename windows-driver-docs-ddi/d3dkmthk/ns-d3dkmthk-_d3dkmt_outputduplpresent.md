# _D3DKMT_OUTPUTDUPLPRESENT structure

## Description

Describes a [Desktop Duplication API](https://learn.microsoft.com/windows/desktop/direct3ddxgi/desktop-dup-api) swapchain present operation.

## Members

### `hContext` [in]

A D3DKMT_HANDLE data type that represents a handle to the context.

### `hSource` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the source allocation to be displayed.

### `VidPnSourceId`

The zero-based identification number of a video present source in a path of a video present network (VidPN) topology.

### `BroadcastContextCount` [in]

Specifies the number of contexts.

### `BroadcastContext` [in]

A D3DKMT_HANDLE data type that represents the broadcast context.

### `PresentRegions` [in]

Dirty and move regions, of type [D3DKMT_PRESENT_RGNS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_rgns).

### `Flags` [in]

A bitwise-OR combination of values from the [D3DKMT_OUTPUTDUPLPRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputduplpresentflags) enumeration that describe options for the present operation.

### `hIndirectContext`

The indirect adapter context for redirecting through the DoD present path. This member is valid only if the PresentIndirect flag is set.

## See also

[D3DKMT_OUTPUTDUPLPRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputduplpresentflags)

[D3DKMT_PRESENT_RGNS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_rgns)