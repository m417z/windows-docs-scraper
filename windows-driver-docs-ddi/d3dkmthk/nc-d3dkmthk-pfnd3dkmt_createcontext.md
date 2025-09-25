# PFND3DKMT_CREATECONTEXT callback function

## Description

The **D3DKMTCreateContext** function creates a kernel-mode device context.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_CREATECONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createcontext) structure that describes the kernel-mode device context.

## Return value

**D3DKMTCreateContext** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The device context was successfully created. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatecontext) could not complete because of insufficient memory. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_CREATECONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createcontext)