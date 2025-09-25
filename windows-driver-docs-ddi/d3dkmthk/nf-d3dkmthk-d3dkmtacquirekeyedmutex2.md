# D3DKMTAcquireKeyedMutex2 function

## Description

Acquires a keyed mutex object that includes private data.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_ACQUIREKEYEDMUTEX2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_acquirekeyedmutex2) structure that specifies the keyed mutex object to acquire.

## Return value

Returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The keyed mutex object was successfully acquired. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTAcquireKeyedMutex2]() could not complete because of insufficient memory. |

This function might also return other **NTSTATUS** values.

## Remarks

**D3DKMTAcquireKeyedMutex2** behaves like the [D3DKMTAcquireKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtacquirekeyedmutex) function but lets the caller specify private data to associate with the keyed mutex.

## See also

[D3DKMTAcquireKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtacquirekeyedmutex)

[D3DKMT_ACQUIREKEYEDMUTEX2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_acquirekeyedmutex2)