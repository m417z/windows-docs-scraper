## Description

The **D3DDDI_TESTCOMMANDBUFFER_FILL** structure describes a fill operation for a test command buffer for kernel-mode testing.

## Members

### `DstAddress`

Destination GPU virtual address for the fill operation.

### `NumBytes`

Number of bytes to fill. **NumBytes** must be a multiple of 4.

### `Pattern`

Pattern to fill. The pattern is 4 bytes that should be copied sequentially.

## Remarks

For more information, see [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features).

## See also

[**D3DDDI_TESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer)

[**D3DDDI_TESTCOMMANDBUFFER_COPY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer_copy)

[**pfnBuildTestCommandBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildtestcommandbuffer)