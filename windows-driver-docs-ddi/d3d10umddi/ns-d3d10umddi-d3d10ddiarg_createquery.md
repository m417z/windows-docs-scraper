# D3D10DDIARG_CREATEQUERY structure

## Description

The D3D10DDIARG_CREATEQUERY structure describes the query to create.

## Members

### `Query` [in]

A [D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query)-typed value that identifies the type of query to create.

### `MiscFlags` [in]

A valid bitwise OR of flag values for the query. Currently, the Direct3D runtime supports only the D3D10DDI_QUERY_MISCFLAG_PREDICATEHINT (0x1) flag. This flag is set along with a D3DQUERYTYPE_OCCLUSIONPREDICATE query type to indicate that the predicate query is a hint. If a predicate query is indicated as a hint (versus guaranteed), no result is ever propagated back to the calling application.

## Remarks

The Direct3D runtime calls the user-mode display driver's [CreateQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createquery) function with a query type to create resources for a query. For information about the type of resources the user-mode display driver creates, see the values of the [D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query) enumeration.

## See also

[CalcPrivateQuerySize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatequerysize)

[CreateQuery(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createquery)

[D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query)