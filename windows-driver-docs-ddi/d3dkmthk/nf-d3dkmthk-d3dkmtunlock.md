# D3DKMTUnlock function

## Description

The **D3DKMTUnlock** function unlocks a list of allocations.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unlock) structure that describes a list of allocations to unlock.

## Return value

**D3DKMTUnlock** returns one of the following values;

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The allocations were successfully unlocked. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

All of the allocations that the **D3DKMTUnlock** function unlocks must belong to the same device.

### Examples

The following code examples demonstrates how an OpenGL ICD can use **D3DKMTUnlock** to unlock three allocations.

```cpp
HRESULT UnlockThree(D3DKMT_HANDLE hDevice,
                    D3DKMT_HANDLE hAllocation1,
                    D3DKMT_HANDLE hAllocation2,
                    D3DKMT_HANDLE hAllocation3)
{
    D3DKMT_HANDLE AllocationArray[3];
    D3DKMT_UNLOCK UnlockData;

    AllocationArray[0] = hAllocation1;
    AllocationArray[1] = hAllocation2;
    AllocationArray[2] = hAllocation3;

    UnlockData.hDevice = hDevice;
    UnlockData.NumAllocations = 3;
    UnlockData.phAllocations = AllocationArray;

    if (NT_SUCCESS((*pfnKTUnlock)(&UnlockData))) {
        return S_OK;
    }
    return E_FAIL;
}
```

## See also

[D3DKMT_UNLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_unlock)