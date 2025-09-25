## Description

The **DXGKARG_BUILDTESTCOMMANDBUFFER** structure describes a test command buffer for [**DXGKDDI_BUILDTESTCOMMANDBUFFER::pfnBuildTestCommandBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildtestcommandbuffer).

## Members

### `hContext`

[in] KMD context handle returned from [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) when [**Flags.HardwareQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_buildtestcommandbufferflags) is 0, or KMD hardware queue handle returned from [**DxgkDdiCreatehwqueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue) when **Flags.HardwareQueue** is 1.

### `Command`

[in] A [**D3DDDI_TESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer) structure that describes the test command for which DMA buffer needs to be generated.

### `pDmaBuffer`

[in/out] Pointer to the buffer in which KMD should write the generated commands to.

### `pDmaBufferPrivateData`

[in/out] Pointer to the buffer in which KMD can write data that is relevant to the execution of generated device instructions.

### `DmaBufferSize`

[in/out] On input, specifies the size in bytes of the buffer that **pDmaBuffer** points to. On output, specifies the number of bytes that KMD has written to the buffer. See [**DXGKDDI_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildtestcommandbuffer) for more information.

### `DmaBufferPrivateDataSize`

[in/out] On input, specifies the size in bytes of the buffer that **pDmaBufferPrivateData** points to. On output, specifies the number of bytes that KMD has written to the buffer. See [**DXGKDDI_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildtestcommandbuffer) for more information.

### `Flags`

[in] A [**D3DDDI_BUILDTESTCOMMANDBUFFERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_buildtestcommandbufferflags) structure that describes the flags for the test command buffer.

## Remarks

For more information, see [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features).

## See also

[**D3DDDI_BUILDTESTCOMMANDBUFFERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_buildtestcommandbufferflags)

[**D3DDDI_TESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer)

 [**DXGKDDI_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildtestcommandbuffer)