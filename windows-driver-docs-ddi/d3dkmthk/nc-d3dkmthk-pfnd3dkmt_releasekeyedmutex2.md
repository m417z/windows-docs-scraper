# PFND3DKMT_RELEASEKEYEDMUTEX2 callback function

## Description

Releases a keyed mutex object that includes private data.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_RELEASEKEYEDMUTEX2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_releasekeyedmutex2) structure that specifies the keyed mutex object to release.

## Return value

Returns one of the following values.

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The keyed mutex object was successfully released. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTReleaseKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreleasekeyedmutex2) could not complete because of insufficient memory. |

This function might also return other NTSTATUS values.

## Remarks

**D3DKMTReleaseKeyedMutex2** behaves like
the [D3DKMTReleaseKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreleasekeyedmutex) function but lets
the caller specify private data to associate with the keyed mutex.

## See also

[D3DKMTReleaseKeyedMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreleasekeyedmutex)

[D3DKMT_RELEASEKEYEDMUTEX2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_releasekeyedmutex2)