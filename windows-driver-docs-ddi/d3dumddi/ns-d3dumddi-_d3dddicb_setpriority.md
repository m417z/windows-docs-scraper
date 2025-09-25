# _D3DDDICB_SETPRIORITY structure

## Description

The D3DDDICB_SETPRIORITY structure describes the priority level to which to set a resource or list of allocations.

## Members

### `hResource` [in]

A handle to a resource whose priority must be set. If the user-mode display driver uses the array that is specified by **HandleList** to set the priority for the list of allocations, it sets **hResource** to **NULL**. If the user-mode display driver sets **hResource** to a non-**NULL** value, it must set the **NumAllocations** member to zero and **HandleList** to **NULL**.

If **hResource** is non-**NULL**, all of the allocations that belong to the resource are set to the priority that is specified by the first element in the array that **pPriorities** points to.

### `NumAllocations` [in]

The number of allocations in the **HandleList** array. If the user-mode display driver sets the handle in the **hResource** member to a non-**NULL** value, it must set **NumAllocations** to zero.

### `HandleList` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the allocations. The Microsoft Direct3D runtime's [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function returns these handles. Therefore, the user-mode display driver uses these handles to set priority for the allocations.

If the user-mode display driver sets the handle in the **hResource** member to a non-**NULL** value, it must set **HandleList** to **NULL**.

### `pPriorities` [in]

A pointer to an array of priority levels. If the **hResource** member is non-**NULL**, the array must contain a single element. If **hResource** is **NULL**, the number of elements in the array is specified by the **NumAllocations** member, and each allocation in the array that is specified by **HandleList** is set to the priority level of the corresponding element in **pPriorities**. For a list of defined priority levels, see the Remarks section of the [pfnSetPriorityCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setprioritycb) reference page.

## See also

[pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)

[pfnSetPriorityCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setprioritycb)