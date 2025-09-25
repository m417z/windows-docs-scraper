# DXGKARGCB_ENUMHANDLECHILDREN structure

## Description

The **DXGKARGCB_ENUMHANDLECHILDREN** structure contains the arguments used in the [**DXGKCB_ENUMHANDLECHILDREN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_enumhandlechildren) callback function, to enumerate allocations associated with a parent resource.

## Members

### `hObject` [in]

A handle to the parent resource of a group of child allocations. This handle is the kernel-mode handle that the DirectX graphics kernel subsystem (part of *Dxgkrnl.sys*) assigned for the parent resource.

### `Index` [in]

The index into the array of child allocations that belongs to the resource that **hObject** specifies.

## See also

[**DXGKCB_ENUMHANDLECHILDREN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_enumhandlechildren)