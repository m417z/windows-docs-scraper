# D3DKMTLock function

## Description

The **D3DKMTLock** function locks an entire allocation or specific pages within an allocation.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_lock) structure that describes parameters for locking an allocation.

## Return value

**D3DKMTLock** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The allocation was successfully locked.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|
|STATUS_GRAPHICS_ALLOCATION_BUSY|The allocation was currently in use and could not be locked.|
|STATUS_GRAPHICS_TOO_MANY_REFERENCES|Too many references were pending on the allocation.|
|STATUS_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION|The allocation could not be locked because a deswizzling aperture was unavailable and because the allocation is pinned and could not be evicted.|

This function might also return other NTSTATUS values.

## Remarks

The **D3DKMTLock** function is called to access system memory allocations and video memory allocations.

#### Examples

The following code example demonstrates how an OpenGL ICD can use **D3DKMTLock** to lock an entire allocation.

```cpp
VOID* LockEntireAllocation(D3DKMT_HANDLE hDevice, D3DKMT_HANDLE hAllocation, UINT PrivateData)
{
    D3DKMT_LOCK LockAllocation = {0};

    LockAllocation.hDevice = hDevice;
    LockAllocation.hAllocation = LockData.hAllocation;
    LockAllocation.Flags.LockEntire = TRUE;
    LockAllocation.PrivateDriverData = PrivateData;
    LockAllocation.NumPages = 0;
    LockAllocation.pPages = NULL;

    if (NT_SUCCESS((*pfnKTLock)(&LockAllocation))) {
        return LockAllocation.pData;
    }
    return NULL;
}
```

## See also

[D3DKMT_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_lock)