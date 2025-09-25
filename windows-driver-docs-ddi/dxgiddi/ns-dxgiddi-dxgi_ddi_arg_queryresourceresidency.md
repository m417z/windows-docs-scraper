# DXGI_DDI_ARG_QUERYRESOURCERESIDENCY structure

## Description

The DXGI_DDI_ARG_QUERYRESOURCERESIDENCY structure describes the residency status of a list of resources.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver determines resource residency status. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `pResources` [in]

An array of handles to the resources to query for residency on.

### `pStatus` [out]

A pointer to an array of DXGI_DDI_RESIDENCY values. The number of elements in the array is specified by the **Resources** member, and each element receives one of the following values to indicate the residency status of the corresponding resource in the array that **pResources** specifies.

| **Value** | **Meaning** |
|:--|:--|
| DXGI_DDI_RESIDENCY_FULLY_RESIDENT (1) | The resources reside in GPU memory, which is the highest residency status. |
| DXGI_DDI_RESIDENCY_RESIDENT_IN_SHARED_MEMORY (2) | The resources reside in shared memory. |
| DXGI_DDI_RESIDENCY_EVICTED_TO_DISK (3) | The resources are nonresident, which is the lowest residency status. |

### `Resources` [in]

The number of elements in the *pResources* and *pStatus* arrays.

## See also

[QueryResourceResidencyDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)