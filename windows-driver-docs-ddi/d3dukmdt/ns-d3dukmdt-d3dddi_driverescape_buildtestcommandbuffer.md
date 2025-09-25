## Description

The **D3DDDI_DRIVERESCAPE_BUILDTESTCOMMANDBUFFER** structure defines the kernel-mode driver (KMD) escape for building a test command buffer.

## Members

### `EscapeType`

[in] A [**D3DDDI_DRIVERESCAPETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_driverescapetype). Must be set to **D3DDDI_DRIVERESCAPETYPE_BUILDTESTCOMMANDBUFFER**.

### `hDevice`

[in] Handle to the display device.

### `hContext`

[in] KMD context handle returned from [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) when [**Flags.HardwareQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_buildtestcommandbufferflags) is 0, or KMD hardware queue handle returned from [**DxgkDdiCreatehwqueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue) when **Flags.HardwareQueue** is 1.

### `Flags`

[in] A [**D3DDDI_BUILDTESTCOMMANDBUFFERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_buildtestcommandbufferflags) structure that specifies flags to use when building a command buffer for kernel-mode testing.

### `Command`

[in] A [**D3DDDI_TESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer) structure that describes the command buffer to build.

### `pDmaBuffer`

[in/out] Pointer to the buffer in which KMD should write the generated commands to.

### `DmaBufferSize`

[in/out] On input, specifies the size in bytes of the buffer that **pDmaBuffer** points to. On output, specifies the number of bytes that KMD has written to the buffer. See [**DXGKDDI_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildtestcommandbuffer) for more information.

### `pDmaBufferPrivateData`

[in/out] Pointer to the buffer in which KMD can write data that is relevant to the execution of generated device instructions.

### `DmaBufferPrivateDataSize`

[in/out] On input, specifies the size in bytes of the buffer that **pDmaBufferPrivateData** points to. On output, specifies the number of bytes that KMD has written to the buffer. See [**DXGKDDI_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildtestcommandbuffer) for more information.

## Remarks

This structure is used by test applications that don't know the specifics of internal device formats.

For more information, see [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features).

## See also

[**DXGKARG_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_escape)

[**DXGKDDI_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape)