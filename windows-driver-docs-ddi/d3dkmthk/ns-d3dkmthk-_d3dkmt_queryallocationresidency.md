# _D3DKMT_QUERYALLOCATIONRESIDENCY structure

## Description

The D3DKMT_QUERYALLOCATIONRESIDENCY structure describes information for retrieving the residency status from a resource or list of allocations.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device that the resource or list of allocations are associated with.

### `hResource` [in]

A handle to a resource whose residency is queried. If the OpenGL ICD uses the array that **phAllocationList** specifies to query for residency, it sets **hResource** to **NULL**. If the OpenGL ICD sets **hResource** to a non-**NULL** value, it must set the **AllocationCount** member to zero and **phAllocationList** to **NULL**.

If **hResource** is non-**NULL**, all of the allocations that belong to the resource are queried, and the result is returned in the first element of the array that **pResidencyStatus** points to.

If any allocation that belongs to the resource is not resident, the entire resource is considered not resident.

To retrieve detailed residency information about each allocation that belongs to a resource, the allocation must be queried.

### `phAllocationList` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the allocations. The OpenGL ICD uses these handles to query for residency status.

If the OpenGL ICD sets the handle in the **hResource** member to a non-**NULL** value, it must set **phAllocationList** to **NULL**.

### `AllocationCount` [in]

The number of allocations in the array that **phAllocationList** specifies. If the OpenGL ICD sets the handle in the **hResource** member to a non-**NULL** value, it must set **AllocationCount** to zero.

### `pResidencyStatus` [out]

A pointer to an array of D3DKMT_ALLOCATIONRESIDENCYSTATUS enumerators. If the **hResource** member is non-**NULL**, the array contains a single element and receives one of the enumerators that are listed in the following table to indicate the residency status of the resource. If **hResource** is **NULL**, the number of elements in the array is specified by the **AllocationCount** member, and each element receives one of the following enumerators to indicate the residency status of the corresponding allocation in the **phAllocationList** array.

|Enumerator|Meaning|
|--- |--- |
|D3DKMT_ALLOCATIONRESIDENCYSTATUS_RESIDENTINGPUMEMORY (1)|The resource or allocation resides in GPU memory.|
|D3DKMT_ALLOCATIONRESIDENCYSTATUS_RESIDENTINSHAREDMEMORY (2)|The resource or allocation resides in shared memory.|
|D3DKMT_ALLOCATIONRESIDENCYSTATUS_NOTRESIDENT (3)|The resource or allocation is nonresident.|

## See also

[D3DKMTQueryAllocationResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryallocationresidency)