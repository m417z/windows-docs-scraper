# D3DKMTLock2 function

## Description

The **D3DKMTLock2** function locks an entire allocation or specific pages within an allocation.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_LOCK2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_lock2) structure that describes parameters for locking an allocation.

## Return value

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The allocation was successfully locked.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|
|STATUS_GRAPHICS_ALLOCATION_BUSY|The allocation was currently in use and could not be locked.|
|STATUS_GRAPHICS_TOO_MANY_REFERENCES|Too many references were pending on the allocation.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_LOCK2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_lock2)