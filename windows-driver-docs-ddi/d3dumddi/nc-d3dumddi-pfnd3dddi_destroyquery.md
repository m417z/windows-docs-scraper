# PFND3DDDI_DESTROYQUERY callback function

## Description

The **DestroyQuery** function releases resources for a query.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `HANDLE`

*hQuery* [in]

A handle to the query that the [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function created.

## Return value

**DestroyQuery** returns S_OK or an appropriate error result if the resources are not released.

## Remarks

The **DestroyQuery** function notifies the driver to destroy the query handle that the [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function previously created. The driver can then release resources that are associated with the query handle.

## See also

[CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)