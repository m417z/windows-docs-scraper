# D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN structure

## Description

The **D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN** structure identifies a flip present-history operation.

## Members

### `FenceValue`

[in] A 64-bit value that specifies the fence value that is used for the flip.

### `hLogicalSurface`

[in] A 64-bit value that specifies the handle to a logical surface.

### `dxgContext`

The DirectX graphics context.

### `VidPnSourceId`

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the monitor is connected to.

### `SwapChainIndex`

[in] The index of the surface in the swap chain that is used for the flip.

### `PresentLimitSemaphoreId`

[in] A 64-bit value that identifies the present-limit semaphore.

### `FlipInterval`

[in] A [**D3DDDI_FLIPINTERVAL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)-typed value that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs).

### `Flags`

[in] A [**D3DKMT_FLIPMODEL_PRESENTHISTORYTOKENFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipmodel_presenthistorytokenflags) structure that identifies, in bit-field flags, attributes of a flip present-history operation.

### `hCompSurf`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `compSurfLuid`

LUID for the composition surface.

### `confirmationCookie`

Confirmation cookie.

### `CompositionSyncKey`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `RemainingTokens`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `ScrollRect`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `ScrollOffset`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `PresentCount`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `RevealColor[4]`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `Rotation`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `ScatterBlts`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `hSyncObject`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `InkCookie`

Cookie for token's ink.

### `SourceRect`

The source rectangle.

### `DestWidth`

The destination width.

### `DestHeight`

The destination height.

### `TargetRect`

The target rectangle.

### `Transform[6]`

Transformation matrix.

### `CustomDuration`

Custom duration of the transition.

### `CustomDurationFlipInterval`

Custom interval of the transition.

### `PlaneIndex`

Index of the plane.

### `ColorSpace`

The color space of the data.

### `DirtyRegions`

[in] A [**D3DKMT_DIRTYREGIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dirtyregions) structure that identifies the active rectangles (dirty regions) of the flip surface.

### `HDRMetaDataHDR10`

### `HDRMetaDataHDR10Plus`

### `HDRMetaDataType`

## See also

[**D3DKMT_FLIPMODEL_PRESENTHISTORYTOKENFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipmodel_presenthistorytokenflags)

[**D3DDDI_FLIPINTERVAL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)

[**D3DKMT_PRESENTHISTORYTOKEN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_presenthistorytoken)

[**D3DKMT_DIRTYREGIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dirtyregions)