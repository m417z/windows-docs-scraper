# D3DKMTAcquireKeyedMutex function

## Description

The **D3DKMTAcquireKeyedMutex** function acquires a keyed mutex object.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_ACQUIREKEYEDMUTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_acquirekeyedmutex) structure that specifies the keyed mutex object to acquire.

## Return value

**D3DKMTAcquireKeyedMutex** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The keyed mutex object was successfully acquired. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTAcquireKeyedMutex]() could not complete because of insufficient memory. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_ACQUIREKEYEDMUTEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_acquirekeyedmutex)