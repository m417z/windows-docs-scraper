# DXGKDDI_MAPCPUHOSTAPERTURE callback function

## Description

**DxgkDdiMapCpuHostAperture** is called to map an allocation that is resident in a local memory segment into the CPU host aperture in order to make it visible to the CPU.

## Parameters

### `hAdapter`

A handle to the display adapter.

### `pArgs`

*Map* [in]

The [DXGKARG_MAPCPUHOSTAPERTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_mapcpuhostaperture) structure that describes the operation.

## Return value

 Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes defined in **Ntstatus.h**.