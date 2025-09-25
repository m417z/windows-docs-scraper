# PFND3DDDI_UPDATEGPUVIRTUALADDRESSCB callback function

## Description

**pfnUpdateGpuVirtualAddressCb** is a special operation used in the context of tile resources. It allows the user mode driver to specify a number of mapping operations to be applied to the process' virtual address space in a single batch of page table updates.

The range of graphics processing unit (GPU) virtual addresses in all operations (except for the source address of copy operations) must belong to a single virtual address range that was obtained by calling [pfnReserveGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb). Similarly, the virtual address ranges of all sources in copy operations must belong to a single virtual address range, which was obtained by calling *pfnReserveGpuVirtualAddressCb*.

The page table updates are executed on a paging context, dedicated to the rendering context specified, and executed on the GPU only after the associated rendering context signaled **FenceValue** for the specified monitored fence object. When the page table updates are finished, the paging context signals the monitored fence object to **FenceValue**+1, allowing the rendering context to do tight interlocking with the page table updates.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_UPDATEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_updategpuvirtualaddress) structure that describes the operation to perform.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The virtual address ranges in the update operations are allowed to intersect. The operations will be applied in the order they are submitted.

In a single **pfnUpdateVirtualAddressCb** call:

* All virtual address ranges in mapping operations and the destination range in copy operations must belong to the same reserved (zero) range.
* The source virtual address range in copy operations is allowed to be from a different reserved (zero) range.
* The source virtual address range in all copy operations must belong to the same reserved (zero) range.

The user mode driver can submit many **pfnUpdateGpuVirtualAddressCb** calls and operations will be queued behind the rendering fence. When the number of queued update operations exceeds 128, the calling thread will be blocked until the previous operations are processed by the video memory manager.

## See also

[D3DDDICB_UPDATEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_updategpuvirtualaddress)

[pfnReserveGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reservegpuvirtualaddresscb)