# DXGI_DDI_ARG_SETRESOURCEPRIORITY structure

## Description

The DXGI_DDI_ARG_SETRESOURCEPRIORITY structure describes parameters for setting the priority level of a resource.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver sets the eviction-from-memory priority for a resource. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `hResource` [in]

A handle to the resource to set the priority level for.

### `Priority` [in]

The priority level to set for the resource that the **hResource** member specifies. A resource's priority level can be set anywhere in the range from 0 through 0xFFFFFFFF.

## Remarks

The priority level that a resource is set at determines its eviction order from memory. A resource that is assigned a low priority is evicted before a resource with a high priority. If two resources have the same priority, the resource that was used more recently is kept in memory; the other resource is evicted.

## See also

[SetResourcePriorityDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)