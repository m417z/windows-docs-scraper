# D3DKMTCreateSynchronizationObject2 function

## Description

The **D3DKMTCreateSynchronizationObject2** function creates a kernel-mode synchronization object.

## Parameters

### `unnamedParam1`

**pData** [in/out] is a pointer to a [**D3DKMT_CREATESYNCHRONIZATIONOBJECT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createsynchronizationobject2) structure that describes the synchronization object to create.

## Return value

**D3DKMTCreateSynchronizationObject2** returns an **NTSTATUS** value such as one of the following:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The kernel-mode synchronization object was successfully created. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | **D3DKMTCreateSynchronizationObject2** couldn't complete because of insufficient memory. |

## See also

[**D3DKMT_CREATESYNCHRONIZATIONOBJECT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createsynchronizationobject2)