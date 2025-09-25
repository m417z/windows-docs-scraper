# DXGIDDICB_PRESENT structure

## Description

The DXGIDDICB_PRESENT structure describes allocations that content is copied to and from.

## Members

### `hSrcAllocation` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the source allocation. The Microsoft Direct3D runtime's [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function returns this handle. Therefore, the user-mode display driver should use this handle to copy content from.

### `hDstAllocation` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the destination allocation. **hDstAllocation** can be zero if the destination is unknown; kernel mode will determine the destination just before sending the hardware command stream through DMA to the graphics processor.

### `pDXGIContext` [in]

A handle to the Microsoft DirectX Graphics Infrastructure (DXGI) context. This handle is opaque to the driver. The driver should assign the handle from the **pDXGIContext** member of the [DXGI_DDI_ARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present) structure that the driver received in a call to its [PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function to this member.

### `hContext` [in]

A handle to the context that the driver submits the copy operation to. The user-mode display driver previously created this context by calling the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function.

### `BroadcastContextCount` [in]

The number of additional contexts in the array that the **BroadcastContext** member specifies.

### `BroadcastContext` [in]

An array of handles to the additional contexts to broadcast the current present operation to. The **D3DDDI_MAX_BROADCAST_CONTEXT** constant, which is defined as 64, defines the maximum number of additional contexts that the user-mode display driver can broadcast the current present operation to.

Broadcasting is supported only for flip operations. To broadcast a flip operation, the display miniport driver must support memory mapped I/O (MMIO)-based flips. To indicate support of MMIO flips, the display miniport driver sets the **FlipOnVSyncMmIo** bit-field flag in the **FlipCaps** member of the [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure when its [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called.

The original context that the **hContext** member specifies and that the user-mode display driver presents to is not an element in the **BroadcastContext** array. For example, if the **BroadcastContext** array contains one element, the user-mode display driver sends the present operation to the owning context (**hContext**) and broadcasts to that one additional context.

### `BroadcastSrcAllocation`

Allocations which content will be presented.

### `BroadcastDstAllocation`

If non-zero, represents the destination allocations of the present.

### `PrivateDriverDataSize`

Private driver data size in bytes.

### `pPrivateDriverData`

Private driver data to pass to DxgiPresent.

### `bOptimizeForComposition`

DWM is involved in composition.

### `SyncIntervalOverrideValid`

Override app sync interval is valid.

### `SyncIntervalOverride`

Override app sync interval.

## See also

[DXGI_DDI_ARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)

[pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85))

[pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb)