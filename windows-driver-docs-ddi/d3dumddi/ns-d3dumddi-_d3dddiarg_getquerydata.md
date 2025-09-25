# _D3DDDIARG_GETQUERYDATA structure

## Description

The D3DDDIARG_GETQUERYDATA structure contains query information that was retrieved from the user-mode display driver.

## Members

### `hQuery` [in]

The handle to the query that was created by the [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function.

### `pData` [out]

A pointer to a buffer that the driver fills with data that is related to a query, if the query type is one that requires data.

## See also

[CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery)

[GetQueryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getquerydata)