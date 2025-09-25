# DXGKDDI_VALIDATESUBMITCOMMAND callback function

## Description

The kernel-mode display miniport's (KMD's) **DXGKDDI_VALIDATESUBMITCOMMAND** function validates private driver data that the user-mode driver (UMD) passes in calls to [**D3DKMTSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) or [**D3DKMTSubmitCommandToHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsubmitcommandtohwqueue).

## Parameters

### `hContext`

[in] A handle to the miniport device context, which the KMD returned from [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device).

### `pArgs`

[in/out] Pointer to a [**DXGKARG_VALIDATESUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_validatesubmitcommand) structure containing information needed to validate the submit command.

## Return value

**DXGKDDI_VALIDATESUBMITCOMMAND** returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) value such as one of the following:

* STATUS_SUCCESS
* STATUS_INVALID_USER_BUFFER

## Remarks

When the KMD implements this callback, the KMD always validates private data passed in calls to:

* [**DxgkDdiSubmitCommandVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandvirtual)
* [**DxgkDdiSubmitCommandToHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandtohwqueue)

This callback is called only when the private driver size ([**DmaBufferPrivateDataSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_submitcommand)) in [**D3DKMTSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) is not zero.

It is called once per **D3DKMTSubmitCommand** or [**D3DKMTSubmitCommandToHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsubmitcommandtohwqueue).

The KMD should not assume that this callback is called in the context of the process that called **D3DKMTSubmitCommand**. Therefore, the UMD should not pass any user-mode pointers or handles in its private data.

This callback is called before the command is submitted to the GPU scheduler software queue for execution.

## See also

[**DXGKARG_VALIDATESUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_validatesubmitcommand)