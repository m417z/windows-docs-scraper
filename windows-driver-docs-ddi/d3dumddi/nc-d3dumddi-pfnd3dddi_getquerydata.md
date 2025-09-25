# PFND3DDDI_GETQUERYDATA callback function

## Description

The *GetQueryData* function retrieves information about a query.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_GETQUERYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getquerydata) structure that contains the information about the query that is retrieved from the driver.

## Return value

*GetQueryData* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The query operation completed and the query result is available.|
|S_FALSE|GetQueryData returned successfully. However, the query operation did not complete, so the query result is not available.|
|E_OUTOFMEMORY|GetQueryData could not allocate the required memory for it to complete.|

## Remarks

The Microsoft Direct3D runtime can call *GetQueryData* at any time after calling the user-mode display driver's [IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery) function. The user-mode display driver should check the current fence value against the value that is stored in the driver's private query structure to determine if the query issue is complete.

If the query is completed, the driver should return S_OK; otherwise, the driver should return S_FALSE.

If a driver supports [runtime-handled multiple-processor optimizations](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-multiple-processors) and exposes a DDI version of 0x0000000B or greater, the runtime will call *GetQueryData* in a reentrant manner. The driver returns the DDI-version value in the **DriverVersion** member of the [D3D10DDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openadapter) structure in a call to the driver's [OpenAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter) function. When the runtime calls *GetQueryData* in a reentrant manner, one thread can execute inside *GetQueryData* while another thread that references the same display device executes inside of another user-mode display driver function.

## See also

[D3DDDIARG_GETQUERYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getquerydata)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery)