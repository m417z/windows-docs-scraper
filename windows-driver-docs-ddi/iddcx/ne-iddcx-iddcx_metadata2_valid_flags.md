## Description

A **IDDCX_METADATA2_VALID_FLAGS** enumeration value indicates which fields in an [**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2) structure have valid content.

## Constants

### `IDDCX_METADATA2_VALID_FLAGS_NONE:0`

Indicates that none of the optional fields in **IDDCX_METADATA2** contain valid data and they should not be referenced.

### `IDDCX_METADATA2_VALID_FLAGS_SYSTEMBUFFERINFO:0x1`

When set, [**IDDCX_METADATA2::SystemBufferInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2) contains valid data. The OS sets this flag in response to a driver setting [**IDARG_IN_RELEASEANDACQUIREBUFFER2::AcquireSystemMemoryBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_releaseandacquirebuffer2) to TRUE.

### `IDDCX_METADATA2_VALID_FLAGS_HDR10METADATA:0x2`

When set, [**IDDCX_METADATA2::Hdr10FrameMetaData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2) contains valid data.

### `IDDCX_METADATA2_VALID_FLAGS_D3D12_SURFACE:0x4`

When a driver has associated an **ID3D12Device** object with a swap chain in a call to [**IddCxSwapChainSetDevice2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainsetdevice2), this flag is set to indicate the **[IDDCX_METADATA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2)::pD3D12Surface** field contains valid data. Note that **IDDCX_METADATA2::pSurface** is null in this situation.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

For more information about D3D12 support, see [IddCx version 1.11 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.11-updates).

## See also

[**IDARG_OUT_RELEASEANDACQUIREBUFFER2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_releaseandacquirebuffer2)

[**IDDCX_METADATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_metadata2)

[**IddCxSwapChainReleaseAndAcquireBuffer2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxswapchainreleaseandacquirebuffer2)