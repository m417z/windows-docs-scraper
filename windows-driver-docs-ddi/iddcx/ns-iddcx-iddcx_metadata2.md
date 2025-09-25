## Description

**IDDCX_METADATA2** provides information about the current provided surface and what is displayed on it.

## Members

### `Size`

Total size of the structure, in bytes.

### `ValidFlags`

A bitwise-OR of [**IDDCX_METADATA2_VALID_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_metadata2_valid_flags) values that indicate which fields in this structure have valid content.

### `PresentationFrameNumber`

Presentation frame number of this surface.

### `DirtyRectCount`

Number of dirty rects for this frame. Call [**IddCxSwapChainGetDirtyRects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchaingetdirtyrects) to get the dirty rects.

A **DirtyRectCount** of 1, where the single dirty rect has all values set to zero, indicates that there has not been any image updates from the previous frame. In this situation, the driver has the opportunity to re-encode the desktop image again to increase the visual quality. Once there are no more updates, the OS presents the same frame as many times as indicated by the [**IDDCX_ADAPTER_CAPS::StaticDesktopReencodeFrameCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps) value , then stops presenting until the next update.

### `HwProtectedSurface`

Indicates whether the provided surface is hardware protected.

### `PresentDisplayQPCTime`

System QPC time of when this surface should be displayed on the indirect display monitor.

### `pSurface`

Pointer to a [**IDXGIResource**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiresource) DX surface that contains the image to encode and transmit. The driver can use this DX surface anytime until [**IddCxSwapChainReleaseAndAcquire**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer) is called again.

### `SurfaceColorSpace`

A [**DXGI_COLOR_SPACE_TYPE**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) value that indicates the color space of the provided surface. The color space typically matches that specified in the committed path.

### `SdrWhiteLevel`

The white level in nits for any SDR content; for example, the mouse cursor. This value always defaults to 80 nits for non-HDR modes.

### `SystemBufferInfo`

An [**IDDCX_SYSTEM_BUFFER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_system_buffer_info) structure in which the resulting information from the [release and acquire operation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)
is returned.

### `Hdr10FrameMetaData`

An [**IDDCX_HDR10_FRAME_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_hdr10_frame_metadata) structure that contains the HDR10 metadata to use with this frame.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_OUT_RELEASEANDACQUIREBUFFER2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquirebuffer2)

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)