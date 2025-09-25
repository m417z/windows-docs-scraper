# D3DKMTOpenSynchronizationObject function

## Description

The **D3DKMTOpenSynchronizationObject** function opens a kernel-mode synchronization object.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_OPENSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensynchronizationobject) structure that describes a shared synchronization object to open.

## Return value

**D3DKMTOpenSynchronizationObject** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The kernel-mode synchronization object was successfully opened. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTOpenSynchronizationObject]() could not complete because of insufficient memory. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_OPENSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_opensynchronizationobject)