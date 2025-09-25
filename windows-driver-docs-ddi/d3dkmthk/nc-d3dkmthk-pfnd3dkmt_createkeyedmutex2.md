# PFND3DKMT_CREATEKEYEDMUTEX2 callback function

## Description

Creates a keyed mutex object that includes private data.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_CREATEKEYEDMUTEX2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2) structure that describes a keyed mutex object to create.

## Return value

Returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The keyed mutex object was successfully created. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTCreateKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex2) could not complete because of insufficient memory. |

This function might also return other NTSTATUS values.

## Remarks

**D3DKMTCreateKeyedMutex2** behaves like the [D3DKMTCreateKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex) function but lets the caller specify private data to associate with the keyed mutex.

Keyed mutexes created with **D3DKMTCreateKeyedMutex2** are still compatible with [D3DKMTOpenKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenkeyedmutex), [D3DKMTAcquireKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtacquirekeyedmutex), and [D3DKMTReleaseKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreleasekeyedmutex) functions.

## See also

[D3DKMTAcquireKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtacquirekeyedmutex)

[D3DKMTCreateKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex)

[D3DKMTOpenKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenkeyedmutex)

[D3DKMTReleaseKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreleasekeyedmutex)

[D3DKMT_CREATEKEYEDMUTEX2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2)