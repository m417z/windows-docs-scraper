# _D3DKMT_SETALLOCATIONPRIORITY structure

## Description

The D3DKMT_SETALLOCATIONPRIORITY structure describes the priority level to set a resource or list of allocations to.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device that the resource or list of allocations are associated with.

### `hResource` [in]

A handle to a resource whose priority must be set. If the OpenGL ICD uses the array that **phAllocationList** specifies to set the priority for the list of allocations, it sets **hResource** to **NULL**. If the OpenGL ICD sets **hResource** to a non-**NULL** value, it must set the **AllocationCount** member to zero and **phAllocationList** to **NULL**.

If **hResource** is non-**NULL**, all of the allocations that belong to the resource are set to the priority that is specified by the first element in the array that **pPriorities** points to.

### `phAllocationList` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the allocations. If the OpenGL ICD sets the handle in the **hResource** member to a non-**NULL** value, it must set **phAllocationList** to **NULL**.

### `AllocationCount` [in]

The number of allocations in the array that **phAllocationList** specifies. If the OpenGL ICD sets the handle in the **hResource** member to a non-**NULL** value, it must set **AllocationCount** to zero.

### `pPriorities` [in]

A pointer to an array of priority levels. If the **hResource** member is non-**NULL**, the array must contain a single element. If **hResource** is **NULL**, the number of elements in the array is specified by the **AllocationCount** member, and each allocation in the array that **phAllocationList** specifies is set to the priority level of the corresponding element in **pPriorities**.

Each element in **pPriorities** can be set to one of the following values.

|Enumerator|Meaning|
|--- |--- |
|D3DDDI_ALLOCATIONPRIORITY_MINIMUM (0x28000000)|Minimum priority|
|D3DDDI_ALLOCATIONPRIORITY_LOW (0x50000000)|Low priority|
|D3DDDI_ALLOCATIONPRIORITY_NORMAL (0x78000000)|Normal priority|
|D3DDDI_ALLOCATIONPRIORITY_HIGH (0xa0000000)|High priority|
|D3DDDI_ALLOCATIONPRIORITY_MAXIMUM (0xc8000000)|Maximum priority|

For more information about the meanings of the preceding values, see the Remarks section of the [pfnSetPriorityCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setprioritycb) function.

## See also

[D3DKMTSetAllocationPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetallocationpriority)