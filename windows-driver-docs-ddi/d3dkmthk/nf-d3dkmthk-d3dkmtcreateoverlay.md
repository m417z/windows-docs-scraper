# D3DKMTCreateOverlay function

## Description

The **D3DKMTCreateOverlay** function creates a kernel-mode overlay object.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createoverlay) structure that describes overlay hardware.

## Return value

**D3DKMTCreateOverlay** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The kernel-mode overlay object was successfully created. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTCreateOverlay]() could not complete because of insufficient memory. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createoverlay)