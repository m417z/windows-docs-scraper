# D3DKMTReserveGpuVirtualAddress function

## Description

**D3DKMTReserveGpuVirtualAddress** reserves an address range in the current process graphics processing unit (GPU) virtual address space. The address range is only reserved, there is no actual memory behind it.

The driver may choose the base GPU virtual address to use for the reservation by specifying a non-NULL value for **BaseAddress**. The video memory manager will use the specified range if it is available. If the range intersects with an existing range, the operation will fail. The driver may pass a **NULL** value in the **BaseAddress** member to let the video memory manager pick a base address.

When the driver chooses to let the video memory manager pick a base address for the GPU virtual address range, it may choose to constrain the range that the video memory manager will consider by specifying non-NULL values for **MinimumAddress** and **MaximumAddress**. The video memory manager will ensure that the allocated GPU virtual address range is entirely contained in the range. The driver may specify only a **MinimumAddress** and the driver will infer the **MaximumAddress** is the end of the address space. If only a **MaximumAddress** is specified, the **MinimumAddress** is inferred to be 0.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DDDI_RESERVEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_reservegpuvirtualaddress) structure that describes the operation.

## Return value

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The device context was successfully created.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.