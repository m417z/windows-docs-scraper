# D3DKMTUpdateGpuVirtualAddress function

## Description

**D3DKMTUpdateGpuVirtualAddress** is a special operation used in the context of tile resources. It allows the driver to specify a number of mapping operations to be applied to the process virtual address space in a single batch of page table updates.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_UPDATEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_updategpuvirtualaddress) structure that describes the operation.

## Return value

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The device context was successfully created. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

The range of graphics processing unit (GPU) virtual addresses in all operations (except the source of the copy operations) must belong to a single virtual address range which was obtained by calling [ReserveGpuVirtualAddressRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_reservegpuvirtualaddressrange). Similarly, the virtual address ranges of all sources in copy operations must belong to a single virtual address range, which was obtained by calling **ReserveGpuVirtualAddressRange**.

The page table updates are executed on a paging context, dedicated to the rendering context specified, and executed on the GPU only after the associated rendering context signaled **FenceValue** for the specified monitored fence object. When the page table updates are finished, the paging context signals the monitored fence object to **FenceValue**+1, allowing the rendering context to do tight interlocking with the page table updates.

The virtual address ranges in the update operations are allowed to intersect. The operations will be applied in the order they are submitted.

In a single **UpdateVirtualAddress** call:

- All virtual address ranges in mapping operations and the destination range in copy operations must belong to the same reserved (zero) range.
- The source virtual address range in copy operations is allowed to be from a different reserved (zero) range.
- The source virtual address range in all copy operations must belong to the same reserved (zero) range.

Drivers can submit many **UpdateGpuVirtualAddress** calls, which will be queued behind the rendering fence. When the number of queued update operations exceeds 128, the calling thread will be blocked until the previous operations are processed by the video memory manager.

## See also

[D3DKMT_UPDATEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_updategpuvirtualaddress)

[ReserveGpuVirtualAddressRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_reservegpuvirtualaddressrange)