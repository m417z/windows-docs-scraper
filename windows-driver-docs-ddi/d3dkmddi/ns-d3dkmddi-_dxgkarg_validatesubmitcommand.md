# DXGKARG_VALIDATESUBMITCOMMAND structure

## Description

The **DXGKARG_VALIDATESUBMITCOMMAND** structure contains arguments used in the call to [**DXGKDDI_VALIDATESUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_validatesubmitcommand).

## Members

### `Commands`

[in] The GPU virtual address of the start of the command buffer.

### `CommandLength`

[in] Length of the command buffer, in bytes.

### `Flags`

[in] A [**DXGK_VALIDATESUBMITCOMMANDFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_validatesubmitcommandflags) value with flags needed to validate the submit command.

### `ContextCount`

[in] Number of valid handles in the **Context** array.

### `Context`

[in] Array of handles to the contexts associated with **Commands**. The handle type is determined as follows.

* **Context** is an array of driver context handles when **Flags.HardwareQueueSubmission** is 0.
* **Context** is an array of driver hardware queue handles when **Flags.HardwareQueueSubmission** is 1.

### `pPrivateDriverData`

[in/out,optional] Pointer to the private data that was passed to [**D3DKMTSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsubmitcommand). This a copy of the buffer and the pointer is a kernel-mode pointer. See Remarks.

### `PrivateDriverDataSize`

[in] The total size in bytes of the private data buffer.

### `UmdPrivateDataSize`

[in] Number of bytes of the private data buffer passed from user mode. See Remarks.

### `HwQueueProgressFenceId`

[in] Identifier that represents the hardware queue progress fence. The driver should use this identifier to ensure that the command buffer has not previously been executed by the GPU when **Flags.HardwareQueueSubmission** is set.

## Remarks

The portion of **pPrivateDriverData**'s buffer that is not passed from user mode is uninitialized. The kernel-mode driver can use this portion to store its own data, which can be consumed in [**DxgkDdiSubmitCommandVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandvirtual).

## See also

[**D3DKMTSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsubmitcommand)

[**DXGKDDI_VALIDATESUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_validatesubmitcommand).