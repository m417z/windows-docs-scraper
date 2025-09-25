# PFND3DDDI_ISSUEQUERY callback function

## Description

The *IssueQuery* function processes a query.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_ISSUEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_issuequery) structure that describes how to process the query.

## Return value

*IssueQuery* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The query is successfully processed.|
|E_OUTOFMEMORY|IssueQuery could not allocate the required memory for it to complete.|

## Remarks

The user-mode display driver should set a fence value and store the fence value in the driver's private query structure. The user-mode display driver implements the query by using a fence. If the *IssueQuery* function is called on a query again before a previous query issue completes, the driver should overwrite the fence value and ignore the previous query issue.

If the call to *IssueQuery* requires the driver to return data, the driver should insert a graphics processing unit (GPU) instruction to write the required data to an allocation. In the call to the [GetQueryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getquerydata) function, the driver should typically lock the allocation and return the appropriate data.

## See also

[CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery)

[D3DDDIARG_ISSUEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_issuequery)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[GetQueryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getquerydata)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)