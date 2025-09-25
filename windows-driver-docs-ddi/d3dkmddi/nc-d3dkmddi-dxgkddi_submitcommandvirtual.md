# DXGKDDI_SUBMITCOMMANDVIRTUAL callback function

## Description

The **DxgkDdiSubmitCommandVirtual** command submits a DMA buffer to a context that supports virtual addressing.

## Parameters

### `hAdapter`

A handle to a context block that is associated with a display adapter. The display miniport driver (KMD) previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSubmitCommand`

A pointer to a [**DXGKARG_SUBMITCOMMANDVIRTUAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_submitcommandvirtual) structure that describes operation.

## Return value

| **Value** | **Description** |
|:--|:--|
| STATUS_SUCCESS | The submitted command is well-formed. |
| STATUS_INVALID_PARAMETER | The DMA or private data is determined to be malformed. In this case, the OS will put the calling device in an error state and all subsequent calls on it will fail. The **SubmissionFenceId** value passed to this call will be considered completed after all previous packets on the hardware finished and at that point the driver notion of the last completed fence ID should be updated to this value. This behavior is different from a call to[**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand), where no error is allowed to be returned due to the ability to validate the data in a prior [**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) call. |

All other return values will lead to an OS bugcheck.

## Remarks

**DxgkDdiSubmitCommandVirtual** works with virtual memory addressing, whereas [**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) is called with physical memory. **DxgkDdiSubmitCommandVirtual** allows the driver to manage memory more flexibly.

The GPU might have previously worked with a different address space, perhaps for another process or context. The driver is responsible for making sure the correct address space is restored ahead of submitting a particular DMA buffer.

## See also

[**DXGKARG_SUBMITCOMMANDVIRTUAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_submitcommandvirtual)

[**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)

[**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand)