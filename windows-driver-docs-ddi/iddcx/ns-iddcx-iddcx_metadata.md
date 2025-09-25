# IDDCX_METADATA structure

## Description

**IDDCX_METADATA** provides information about the current provided surface and what is displayed on it.

## Members

### `Size`

Total size of the structure, in bytes.

### `PresentationFrameNumber`

Presentation frame number of this surface.

### `DirtyRectCount`

Number of dirty rects for this frame. Call [**IddCxSwapChainGetDirtyRects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchaingetdirtyrects) to get the dirty rects.

A MoveRegionCount of zero and DirtyRectCount of 1, where the single dirty rect has all values set to zero, indicates that there has not been any image updates from the previous frame. This is an opportunity for the driver to re-encode the desktop image again to increase the visual quality. Once there are no more updates, the OS presents the same frame as many times as indicated by the [**IDDCX_ADAPTER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps) value **StaticDesktopReencodeFrameCount**, then stops presenting until the next update.

### `MoveRegionCount`

Starting in IddCx v1.7, the [**IDDCX_ADAPTER_FLAGS_CAN_USE_MOVE_REGIONS** flag was deprecated](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.7-updates) and move regions are no longer provided at acquire frame time, so this field will always be zero.

Number of move regions in this frame. Call [**IddCxSwapChainGetMoveRegions**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchaingetmoveregions) to get the move regions.

### `HwProtectedSurface`

Indicates whether the provided surface is hardware protected.

### `PresentDisplayQPCTime`

System QPC time of when this surface should be displayed on the indirect display monitor.

### `pSurface`

Pointer to a [**IDXGIResource**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiresource) DX surface that contains the image to encode and transmit. The driver can use this DX surface anytime until [**IddCxSwapChainReleaseAndAcquire**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer) is called again.

> [!NOTE]
> This surface is always a A8R8G8B8 formatted surface.

## Remarks

A single empty dirty rect indicates there were no desktop updates.

### See also

[**IDDCX_FRAME_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_frame_statistics)