# PFND3DDDI_RESERVEGPUVIRTUALADDRESSCB callback function

## Description

The D3D runtime's **pfnReserveGPUVirtualAddressCb** callback reserves an address range in the current process GPU virtual address space. The address range is only reserved, there is no actual memory behind it.

## Parameters

### `hDevice`

[in] A handle to the display device.

### `unnamedParam2`

[in/out] Pointer to a [**D3DDDI_RESERVEGPUVIRTUALADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_reservegpuvirtualaddress) structure that describes the operation to perform.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The user mode driver (UMD) can choose the base GPU virtual address to use for the reservation by specifying a non-NULL value for **BaseAddress**. The video memory manager (*VidMm*) will use the specified range if it's available. If the range intersects with an existing range, the operation fails. UMD can pass a NULL **BaseAddress** to let *VidMm* pick a base address.

When UMD chooses to let *VidMm* pick a base address for the GPU virtual address range, UMD can choose to constrain the range that *VidMm* should consider by specifying non-NULL values for **MinimumAddress** and **MaximumAddress**. *VidMm* will ensure that the allocated GPU virtual address range is entirely contained in the range. UMD can specify only a **MinimumAddress**, where **MaximumAddress** is assumed to be the end of the address space. Or UMD can specify only a **MaximumAddress**, where **MinimumAddress** is assumed to be 0.

When UMD calls **pfnReserveGpuVertualAddrsesCb** with **hAdapter** set to 0, the D3D runtime will set **hAdapter** to the kernel's D3DKMT_HANDLE before calling the [**D3DKMTReserveGpuVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreservegpuvirtualaddress) kernel interface.

## See also

[**D3DDDI_RESERVEGPUVIRTUALADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_reservegpuvirtualaddress)