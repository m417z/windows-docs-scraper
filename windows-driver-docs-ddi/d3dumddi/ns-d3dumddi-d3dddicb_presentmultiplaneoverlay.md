# D3DDDICB_PRESENTMULTIPLANEOVERLAY structure

## Description

Describes multiplane overlay allocations that content is copied to and from.

## Members

### `hContext` [in]

A handle to the context that the driver submits the copy operation to. The user-mode display driver previously created this context by calling the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function.

### `BroadcastContextCount` [in]

The number of additional contexts in the array that the **BroadcastContext** member specifies.

### `BroadcastContext` [in]

An array of handles to the additional contexts to broadcast the current present operation to. The **D3DDDI_MAX_BROADCAST_CONTEXT** constant, which is defined as 64, defines the maximum number of additional contexts that the user-mode display driver can broadcast the current present operation to.

Broadcasting is supported only for flip operations. To broadcast a flip operation, the display miniport driver must support memory mapped I/O (MMIO)-based flips. To indicate support of MMIO flips, the display miniport driver sets the **FlipOnVSyncMmIo** bit-field flag in the **FlipCaps** member of the [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure when its [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called.

The original context that the **hContext** member specifies and that the user-mode display driver presents to is not an element in the **BroadcastContext** array. For example, if the **BroadcastContext** array contains one element, the user-mode display driver sends the present operation to the owning context (**hContext**) and broadcasts to that one additional context.

### `AllocationInfoCount` [in]

The number of allocations in the array that the **AllocationInfo** member specifies. The maximum number is 16, the value of the **D3DDDI_MAX_MULTIPLANE_OVERLAY_ALLOCATIONS** constant.

### `AllocationInfo`

An array of structures of type [D3DDDI_MULTIPLANE_ALLOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_allocation_info) that specify info about the multiplane overlay allocations.

## See also

[D3DDDI_MULTIPLANE_ALLOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddi_multiplane_overlay_allocation_info)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85))