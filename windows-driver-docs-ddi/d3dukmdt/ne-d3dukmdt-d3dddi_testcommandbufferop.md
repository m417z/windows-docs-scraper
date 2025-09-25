## Description

A **D3DDDI_TESTCOMMANDBUFFEROP** enumeration specifies the type of operation for a test command buffer.

## Constants

### `D3DDDI_TESTCOMMANDBUFFEROP_INVALID:0`

The operation is invalid or not specified.

### `D3DDDI_TESTCOMMANDBUFFEROP_COPY:1`

The command buffer operation is a copy operation.

### `D3DDDI_TESTCOMMANDBUFFEROP_FILL:2`

The command buffer operation is a fill operation.

### `D3DDDI_TESTCOMMANDBUFFEROP_INFINITE_LOOP:3`

The command is used to simulate a hung engine. The generated infinite loop must be not preemptable.

### `D3DDDI_TESTCOMMANDBUFFEROP_INFINITE_PREEMPTABLE_LOOP:4`

The command is used to test preemption of a long running command. The generated infinite loop must be preemptable.

### `D3DDDI_TESTCOMMANDBUFFEROP_MAX`

Maximum value for this enumeration.

## Remarks

For more information, see [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features).

## See also

[**D3DDDI_TESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_testcommandbuffer)

[**pfnBuildTestCommandBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkddi_kernelmodetestinginterface)