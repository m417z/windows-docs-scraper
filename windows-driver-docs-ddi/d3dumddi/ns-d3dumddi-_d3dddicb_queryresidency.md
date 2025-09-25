# _D3DDDICB_QUERYRESIDENCY structure

## Description

The D3DDDICB_QUERYRESIDENCY structure describes the residency status of a resource or list of allocations.

## Members

### `hResource` [in]

A handle to a resource whose residency is queried. If the user-mode display driver uses the array in the **HandleList** member to query for residency, it sets **hResource** to **NULL**.

If **hResource** is non-**NULL**, all allocations that belong to the resource are queried, and the result is returned in the first element of the array that **pResidencyStatus** points to. The residency status of a resource is equal to the lowest residency status of all allocations that belong to the resource.

### `NumAllocations` [in]

The number of allocations in the **HandleList** array. If the user-mode display driver sets the handle in the **hResource** member to non-**NULL**, it must set **NumAllocations** to zero.

### `HandleList` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the allocations. The Microsoft Direct3D runtime's [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function returns these handles. Therefore, the user-mode display driver uses these handles to query for residency.

If the user-mode display driver sets the handle in the **hResource** member to non-**NULL**, it must set **HandleList** to **NULL**.

### `pResidencyStatus` [out]

A pointer to an array of D3DDDI_RESIDENCYSTATUS values. If the **hResource** member is non-**NULL**, the array contains a single element and receives one of the following value to indicate the residency status of the resource. If **hResource** is **NULL**, the number of elements in the array is specified by the **NumAllocations** member, and each element receives one of the following values to indicate the residency status of the corresponding allocation in the array that is specified by **HandleList**.

| **Value** | **Meaning** |
|:--|:--|
| D3DDDI_RESIDENCYSTATUS_RESIDENTINGPUMEMORY (1) | The resource or list of allocations reside in GPU memory, which is the highest residency status. |
| D3DDDI_RESIDENCYSTATUS_RESIDENTINSHAREDMEMORY (2) | The resource or list of allocations reside in shared memory. |
| D3DDDI_RESIDENCYSTATUS_NOTRESIDENT (3) | The resource or list of allocations is nonresident, which is the lowest residency status. |

## See also

[pfnQueryResidencyCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresidencycb)