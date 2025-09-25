# DXGKARGCB_GETHANDLEDATA structure

## Description

The **DXGKARGCB_GETHANDLEDATA** structure contains the arguments used in the [**DXGKCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_getcaptureaddress) callback function.

## Members

### `hObject` [in]

A handle to the private data. This handle is the kernel-mode handle that the DirectX graphics kernel subsystem (part of *Dxgkrnl.sys*) assigned for the private data.

### `Type` [in]

A [**DXGK_HANDLE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_handle_type) value that indicates the type of handle to retrieve data about.

### `Flags` [in]

A [**DXGKCB_GETHANDLEDATAFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkcb_gethandledataflags) structure that indicates if allocations belong to a resource.

## See also

[**DXGKCB_GETHANDLEDATAFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkcb_gethandledataflags)

[**DXGKCB_GETHANDLEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata)

[**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)