# DXGKDDI_UNMAPCPUHOSTAPERTURE callback function

## Description

**DxgkDdiUnmapCpuHostAperture** is used to unmap a previously mapped range of the CPU host aperture.

## Parameters

### `hAdapter`

A handle to the display adapter.

### `pArgs`

A [DXGKARG_UNMAPCPUHOSTAPERTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_unmapcpuhostaperture) structure that describes the operation.

## Return value

 Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes defined in **Ntstatus.h**.

## See also

[DXGKARG_UNMAPCPUHOSTAPERTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_unmapcpuhostaperture)