# D3DKMTSubmitCommand function

## Description

**D3DKMTSubmitCommand** is used to submit command buffers on contexts that support graphics processing unit (GPU) virtual addressing. These contexts generate commands directly from user mode, manage their own command buffer pool and don't make use of the allocation or patch location list.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SUBMITCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitcommand) structure that describes the operation.

## Return value

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The device context was successfully created. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

This function replaces the old [Render](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_renderkm) function for such contexts and must be used in its place. Contexts that operate in legacy patch mode must continue to use the old **Render** function.

Although the user mode driver doesn't generate patch locations, it must still generate a list of primaries, which are being written to. The video memory manager uses the allocation list to determine which primary allocations are being referenced for write by each command buffer. This information is used to synchronize rendering to the primaries with *flip* operations.

Some kernel mode drivers need information from their user mode driver on how to submit a particular direct memory access (DMA) buffer to their GPU. In Windows Display Driver Model (WDDM) 1.0, this information was sent by the user mode driver to the kernel mode driver through the command buffer. Since DMA buffer are built directly by the user mode driver and submitted to the GPU without modification they can't be used to send information to the kernel driver anymore. To enable the transfer of information between the user mode and kernel mode drivers, an explicit private driver data buffer has been added to be sent along with a submission.

> [!NOTE]
> This private driver data is unidirectional and the kernel mode driver can't return information to the user mode driver through this buffer.

## See also

[D3DKMT_SUBMITCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitcommand)