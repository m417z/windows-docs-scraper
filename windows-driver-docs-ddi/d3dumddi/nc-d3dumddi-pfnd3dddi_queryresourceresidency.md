# PFND3DDDI_QUERYRESOURCERESIDENCY callback function

## Description

The *QueryResourceResidency* function determines the residency of the given list of resources.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_QUERYRESOURCERESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_queryresourceresidency) structure that describes a list of resources on which residency is verified.

## Return value

*QueryResourceResidency* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|All of the resources are in GPU-accessible memory.|
|S_RESIDENT_IN_SHARED_MEMORY|No allocations that comprise the resources are on disk. However, at least one allocation is not in GPU-accessible memory.|
|S_NOT_RESIDENT|At least one allocation that comprises the resources is on disk.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|QueryResourceResidency could not allocate memory that is required for it to complete.|

## Remarks

The Microsoft Direct3D runtime calls the user-mode display driver's *QueryResourceResidency* function for applications to determine if the operating system will incur a significant stall at draw time if the system must make resources GPU-accessible. The information that is returned from *QueryResourceResidency* is an approximation of the residency of resources because the resources might become demoted before applications use the resources.

The user-mode display driver's *QueryResourceResidency* function must make calls to the [pfnQueryResidencyCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresidencycb) function. The **pfnQueryResidencyCb** function returns the residency status of a resource in the elements of the array that is specified by the **pResidencyStatus** member of the [D3DDDICB_QUERYRESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_queryresidency) structure. If **pfnQueryResidencyCb** returns D3DDDI_RESIDENCYSTATUS_NOTRESIDENT for any query, *QueryResourceResidency* must return S_NOT_RESIDENT. If **pfnQueryResidencyCb** returns D3DDDI_RESIDENCYSTATUS_RESIDENTINSHAREDMEMORY for any query and does not return D3DDDI_RESIDENCYSTATUS_NOTRESIDENT for any query, *QueryResourceResidency* must return S_RESIDENT_IN_SHARED_MEMORY. *QueryResourceResidency* must return S_OK only if all calls to **pfnQueryResidencyCb** for all queries return D3DDDI_RESIDENCYSTATUS_RESIDENTINGPUMEMORY.

For each resource that the runtime queries through a call to *QueryResourceResidency*, the user-mode display driver must determine which allocations that belong to the resource to query through a call to [pfnQueryResidencyCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresidencycb). For a resource that owns a single allocation, the determination is simple--the driver will query that allocation. However, if a resource owns multiple allocations, the determination is more difficult. The driver must determine which allocations that an application will likely use for rendering, and the driver must query only those allocations. For example, if a resource owns an allocation that is used for rendering and a scratch allocation that handles a lock operation, the driver should query only for the residency of the first allocation, because an application will most likely not use the second allocation for rendering.

**Note** Because the runtime does not support residency-querying of system memory resources, the runtime will always fail requests from applications for the residency status of system memory resources and will never call the user-mode display driver's *QueryResourceResidency* function for these system memory resources.

## See also

[D3DDDIARG_QUERYRESOURCERESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_queryresourceresidency)

[D3DDDICB_QUERYRESIDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_queryresidency)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[pfnQueryResidencyCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresidencycb)