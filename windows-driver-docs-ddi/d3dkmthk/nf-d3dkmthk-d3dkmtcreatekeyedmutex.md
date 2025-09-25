# D3DKMTCreateKeyedMutex function

## Description

The **D3DKMTCreateKeyedMutex** function creates a keyed mutex object.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_CREATEKEYEDMUTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex) structure that describes a keyed mutex object to create.

## Return value

**D3DKMTCreateKeyedMutex** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The keyed mutex object was successfully created. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTCreateKeyedMutex]() could not complete because of insufficient memory. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_CREATEKEYEDMUTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex)