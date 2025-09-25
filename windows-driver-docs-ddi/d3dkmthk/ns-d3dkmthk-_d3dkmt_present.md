# _D3DKMT_PRESENT structure

## Description

The D3DKMT_PRESENT structure describes the present operation.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device to present to. A device handle is supplied to the [D3DKMTPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtpresent) function in the union that D3DKMT_PRESENT contains for compatibility with Microsoft Direct3D version 10.

### `hContext` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device context to present to.

### `hWindow` [in]

A handle to the window that the bit-block transfer (bitblt) applies to. A value of **NULL** indicates the desktop window. The value in **hWindow** can be **NULL** unless the **Blt** or **ColorFill** bit-field flag is specified in the **Flags** member.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology on which to restrict displaying, if the **RestrictVidPnSource** bit-field flag is set in the **Flags** member.

If the **RestrictVidPnSource** bit-field flag is set and the **hWindow** member is **NULL**, the **VidPnSourceId** member indicates which output the full-screen bitblt is directed to If **RestrictVidPnSource** is set and **hWindow** is non-**NULL**, **VidPnSourceId** indicates to which output to restrict the windowed bit-block transfer.

### `hSource` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the system memory or primary allocation to present from, if the **ColorFill** bit-field flag is not set in the **Flags** member.

### `hDestination` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the destination allocation. **hDestination** can be zero if the destination is unknown.

The handle in **hDestination** is valid only if the **Blt** bit-field flag is set in the **Flags** member.

If the handle in the **hDestination** member is nonzero, the **hDestination** and **hWindow** handles must refer to two different primary allocations of the same size, the device in the **hDevice** member must own the video present source that is identified by the **VidPnSourceId** member, and the **SrcRectValid** bit-field flag must be set in the **Flags** member.

### `Color` [in]

The ARGB 32-bit (see the [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration) color-fill or color-key value . A value for color fill is set when the **ColorFill** bit-field flag is set in the **Flags** member. A value for color key is set when either the **SrcColorKey** or **DstColorKey** bit-field flag is set in the **Flags** member. Note that only one of the **ColorFill**, **SrcColorKey**, and **DstColorKey** bit-field flags is set at any time.

If the primary format is palettized RGB, **Color** contains the palette index rather than the D3DDDIFMT_A8R8G8B8 value from D3DDDIFORMAT.

### `DstRect` [in]

The optional destination [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) for the bitblt. The destination RECT is used only if the **DstRectValid** bit-field flag is set in the **Flags** member.

### `SrcRect` [in]

The optional source RECT for the bitblt. The source RECT is used only if the **SrcRectValid** bit-field flag is set in the **Flags** member.

### `SubRectCnt` [in]

The number of subrectangular regions that **pSrcSubRects** points to that are specified when presenting.

### `pSrcSubRects` [in]

A pointer to an array of subrectangular regions (RECTs) that are specified when presenting.

### `PresentCount` [in]

The number of present operations that can be queued for the device that is specified by **hDevice**.

### `FlipInterval` [in]

A [D3DDDI_FLIPINTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)-typed value that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs).

### `Flags` [in]

A [D3DKMT_PRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presentflags) structure that identifies, in bit-field flags, how to display. Note that the **ColorFill**, **SrcColorKey**, and **DstColorKey** bit-field flags are mutually exclusive.

### `BroadcastContextCount` [in]

The number of additional contexts in the array that **BroadcastContext** specifies.

### `BroadcastContext` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the additional contexts to broadcast the current present operation to. The D3DDDI_MAX_BROADCAST_CONTEXT constant, which is defined as 64, defines the maximum number of contexts that the OpenGL ICD can broadcast the current present operation to.

Broadcasting is supported only for flip operations. To broadcast a flip operation, the display miniport driver must support memory mapped I/O (MMIO)-based flips. To indicate support of MMIO flips, the display miniport driver sets the **FlipOnVSyncMmIo** bit-field flag in the **FlipCaps** member of the [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure when its [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called.

The original context that the **hContext** member specifies and that the OpenGL ICD presents to is not an element in the **BroadcastContext** array. For example, if the **BroadcastContext** array contains one element, the OpenGL ICD sends the present operation to the owning context (**hContext**) and broadcasts to that one additional context.

### `PresentLimitSemaphore` [in]

The handle to the present-limit semaphore.

Supported starting with Windows 7.

### `PresentHistoryToken` [in]

A [D3DKMT_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken) structure that identifies the type of present operation.

Supported starting with Windows 7.

### `pPresentRegions`

A pointer to a [D3DKMT_PRESENT_RGNS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_rgns) structure that identifies dirty and move regions.

Supported starting with Windows 8.

### `hAdapter`

A handle to the graphics adapter.

### `hIndirectContext`

The indirect adapter context for redirecting through the DoD present path. This member is valid only if the PresentIndirect flag is set.

### `Duration`

Per-present duration. Valid only when the DurationValid flag is set.

### `BroadcastSrcAllocation`

Linked display adapter for the source.

### `BroadcastDstAllocation`

Linked display adapter for the destination.

### `PrivateDriverDataSize`

Private driver data size.

### `pPrivateDriverData`

Pointer to a buffer that contains optional private driver data.

### `bOptimizeForComposition`

Indicates whether the device is optimized for composition.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DKMTPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtpresent)

[D3DKMT_PRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presentflags)

[D3DKMT_PRESENTHISTORYTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken)

[D3DKMT_PRESENT_RGNS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_rgns)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)