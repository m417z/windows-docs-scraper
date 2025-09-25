# DXGKDDI_SUBMITCOMMAND callback function

## Description

The **DxgkDdiSubmitCommand** function submits a DMA buffer to one of the GPU's hardware command execution units.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver (KMD) previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSubmitCommand` [in]

A pointer to a [**DXGKARG_SUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_submitcommand) structure that describes the DMA buffer that the KMD submits to the hardware command execution unit.

## Return value

**DxgkDdiSubmitCommand** returns **STATUS_SUCCESS** upon successful completion. If the driver instead returns an error code, the operating system causes a system bugcheck to occur. See Remarks.

## Remarks

**DxgkDdiSubmitCommand** works with physical memory addressing, whereas [**DxgkDdiSubmitCommandVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandvirtual) is called with virtual memory.

Because paging operations are considered system operations, they are not associated with a specific application context or graphics context. Therefore, when the submission is for a paging operation, the **DxgkDdiSubmitCommand** function is called with NULL specified in the **hDevice** member of the [**DXGKARG_SUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_submitcommand) structure that the **pSubmitCommand** parameter points to.

However, if the architecture of a particular hardware and driver must have a device internally, the driver must internally create the device during adapter initialization and must keep the device internally as the system default device for use in paging operations.

The driver can write the value that is supplied in the **SubmissionFenceId** member of **DXGKARG_SUBMITCOMMAND** into the fence command in the ring buffer. For more information about fence commands, see [Supplying Fence Identifiers](https://learn.microsoft.com/windows-hardware/drivers/display/supplying-fence-identifiers).

If the driver returns an error code, *Dxgkrnl* causes a system bugcheck to occur. In a crash dump file, the error is noted by the message [**BugCheck 0x119**](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x119---video-scheduler-internal-error), which will have the following four parameters.

* 0x2 (identifies the cause of the error)
* The NTSTATUS error code returned from the failed driver call
* A pointer to the [**DXGKARG_SUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_submitcommand) structure
* A pointer to an internal scheduler data structure

**DxgkDdiSubmitCommand** should be made nonpageable because it runs at IRQL = DISPATCH_LEVEL.

## See also

[**DXGKARG_SUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_submitcommand)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)

[**DxgkDdiSubmitCommandVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandvirtual)