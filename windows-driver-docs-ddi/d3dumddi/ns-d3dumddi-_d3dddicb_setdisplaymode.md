# _D3DDDICB_SETDISPLAYMODE structure

## Description

The D3DDDICB_SETDISPLAYMODE structure describes the primary allocation that is used to scan out to the display.

## Members

### `hPrimaryAllocation` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the primary allocation for scanning out. The Microsoft Direct3D runtime's [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function returns this handle.

### `PrivateDriverFormatAttribute` [out]

A private format attribute that the user-mode display driver should use to convert the current primary surface if the [pfnSetDisplayModeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymodecb) callback function returned D3DDDIERR_INCOMPATIBLEPRIVATEFORMAT.

## Remarks

The user-mode display driver can set the **hPrimaryAllocation** member in the call to [pfnSetDisplayModeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymodecb) to scan out any allocation. However, the allocation must be marked as a primary (that is, the user-mode display driver must have set the **Primary** bit-field flag in the **Flags** member of the [D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structure in a call to the [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function to create the allocation).

## See also

[D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo)

[pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)

[pfnSetDisplayModeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymodecb)