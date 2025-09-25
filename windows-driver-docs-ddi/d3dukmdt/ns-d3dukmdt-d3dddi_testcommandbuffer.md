## Description

The **D3DDDI_TESTCOMMANDBUFFER** structure describes a test command buffer for kernel-mode testing.

## Members

### `Copy`

When **Operation** is **D3DDDI_TESTCOMMANDBUFFEROP_COPY**, this field is a [**D3DDDI_TESTCOMMANDBUFFER_COPY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer_copy) structure for a copy operation.

### `Fill`

When **Operation** is **D3DDDI_TESTCOMMANDBUFFEROP_FILL**, this field is a [**D3DDDI_TESTCOMMANDBUFFER_FILL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer_fill) structure for a fill operation.

### `Reserved[64]`

Reserved for future use.

### `Operation`

A [**D3DDDI_TESTCOMMANDBUFFEROP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_testcommandbufferop) enumeration that specifies the type of operation for the test command buffer, and which operation-specific structure to use.

### `Reserved1`

Reserved.

## Remarks

For more information, see [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features).

## See also

[**D3DDDI_DRIVERESCAPE_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_driverescape_buildtestcommandbuffer)

[**D3DDDI_TESTCOMMANDBUFFER_COPY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer_copy)

[**D3DDDI_TESTCOMMANDBUFFER_FILL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer_fill)

[**D3DDDI_TESTCOMMANDBUFFEROP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_testcommandbufferop)

[**DXGKARG_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_buildtestcommandbuffer)

[**pfnBuildTestCommandBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkddi_kernelmodetestinginterface)