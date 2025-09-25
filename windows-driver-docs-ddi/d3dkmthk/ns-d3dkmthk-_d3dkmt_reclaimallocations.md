# _D3DKMT_RECLAIMALLOCATIONS structure

## Description

Describes video memory resources that are to be reclaimed and that the driver previously offered for reuse. Used with the [D3DKMTReclaimAllocations](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreclaimallocations) function.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a handle to the device that created the allocations.

### `pResources` [in]

An array of **D3DKMT_HANDLE** data types that represent Direct3D runtime resource handles.

### `HandleList` [in]

An array of **D3DKMT_HANDLE** data types that represent kernel-mode handles to the allocations that are to be reclaimed.

If **HandleList** is not **NULL**, the **pResources** member must be **NULL**.

### `pDiscarded` [out]

An array of Boolean values that specify whether each resource or allocation was discarded.

Each Boolean value in this array corresponds to a resource at the same index location in the arrays pointed to by **pResources** or **HandleList.**

The DirectX graphics kernel subsystem sets each Boolean value to **TRUE** if the corresponding resource was discarded, or to **FALSE** if not.

The value of **pDiscarded** can be **NULL**. If the driver sets it to **NULL**, the content of the resource or allocation can be assumed to be lost. If the driver does not need the content of the resource or allocation, setting **pDiscarded** to **NULL** might improve performance.

### `NumAllocations` [in]

The number of items in the **pResources**, **HandleList**, or **pDiscarded** members, whichever is not **NULL**.

## See also

[D3DKMTReclaimAllocations](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreclaimallocations)