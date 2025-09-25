# DXGKDDI_CREATECONTEXT callback function

## Description

The *DxgkDdiCreateContext* function creates a graphics processing unit (GPU) context.

## Parameters

### `hDevice` [in]

A handle to the graphics context device that the new context is created on. The display miniport driver's [DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the **hDevice** member of the [DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice) structure.

### `pCreateContext` [in/out]

A pointer to a [DXGKARG_CREATECONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext) structure that contains information about creating the context.

## Return value

*DxgkDdiCreateContext* returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|DxgkDdiCreateContext successfully created the context.|
|STATUS_NO_MEMORY|DxgkDdiCreateContext could not allocate memory that was required for it to complete.|
|STATUS_GRAPHICS_DRIVER_MISMATCH|The display miniport driver is not compatible with the user-mode display driver that initiated the call to DxgkDdiCreateContext.|

## Remarks

A driver uses a GPU context to hold a collection of rendering state.

A single process can create multiple contexts on a given device.

The driver must support an arbitrary number of contexts. The only valid reason why a driver could not create a context is if system memory runs out.

Typically, each context can reference any resource that was previously created for the device that owns that context.

*DxgkDdiCreateContext* should be made pageable.

## See also

[DXGKARG_CREATECONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext)

[DXGKARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createdevice)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)