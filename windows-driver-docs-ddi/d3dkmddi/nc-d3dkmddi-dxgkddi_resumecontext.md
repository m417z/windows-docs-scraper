# DXGKDDI_RESUMECONTEXT callback function

## Description

**DxgkddiResumeContext** resumes a context. A context is created in a resumed state by default.

## Parameters

### `hAdapter`

[in] The hardware context to be resumed.

### `pResumeContext`

[in] Pointer a [**DXGKARG_RESUMECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_resumecontext) structure that contains information to resume the content.

## Return value

**DxgkddiResumeContext** returns STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS error code.

## Remarks

Register your implementation of this callback function by setting it in [**DRIVER_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_driver_initialization_data).

## See also

[**DxgkddiSuspendContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_suspendcontext)