## Description

The **D3DDDI_TESTCOMMANDBUFFER_COPY** structure describes a copy operation for a test command buffer for kernel-mode testing.

## Members

### `SrcAddress`

The source GPU virtual address for the copy operation.

### `DstAddress`

The destination GPU virtual address for the copy operation.

### `NumBytes`

The number of bytes to copy. **NumBytes** must be a multiple of 4.

## Remarks

**D3DDDI_TESTCOMMANDBUFFER_COPY** is used to copy bytes using source and destination GPU virtual addresses.

For more information, see [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features).

## See also

[**D3DDDI_TESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer)

[**D3DDDI_TESTCOMMANDBUFFER_FILL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer_fill)

[**pfnBuildTestCommandBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_buildtestcommandbuffer)