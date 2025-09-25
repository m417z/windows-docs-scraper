# _D3DDDIARG_CREATEQUERY structure

## Description

The D3DDDIARG_CREATEQUERY structure identifies a query to create.

## Members

### `QueryType` [in]

A [D3DDDIQUERYTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddiquerytype)-typed value that indicates the query type to create resources for.

### `hQuery` [out]

A handle to the query. The user-mode display driver's [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function returns this handle to the Microsoft Direct3D runtime.

## Remarks

The Direct3D runtime uses the handle that is specified by the **hQuery** member when the runtime calls:

* The [IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery) function to process a query.
* The [GetQueryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getquerydata) function to retrieve information about the query.
* The [DestroyQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyquery) function to destroy the handle.

## See also

[CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery)

[DestroyQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyquery)

[GetQueryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getquerydata)

[IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery)