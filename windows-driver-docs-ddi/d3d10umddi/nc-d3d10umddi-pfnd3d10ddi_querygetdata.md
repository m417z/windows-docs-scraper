# PFND3D10DDI_QUERYGETDATA callback function

## Description

The **QueryGetData** function polls for the state of a query operation.

## Parameters

### `unnamedParam1`

*hDevice* [in]: A handle to the display device (graphics context).

### `unnamedParam2`

*hQuery* [in]: A handle to the query object to poll.

### `unnamedParam3`

*pData* [out]: A pointer to a region of memory that receives the data from a query operation. The user-mode display driver can set **pData** to NULL and set the **DataSize** parameter to zero. If **pData** is NULL, **QueryGetData** can indicate the state of the query operation (for example, whether the query operation is finished).

### `DataSize`

[out] The size, in bytes, of the query data that the **pData** parameter points to. The user-mode display driver can set **DataSize** to zero and set **pData** to NULL. If **DataSize** is zero, **QueryGetData** can indicate the state of the query operation (for example, through return codes).

### `unnamedParam5`

*Flags* [in]: D3D10_DDI_GET_DATA_FLAG flags.

## Remarks

The driver can use the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

After the Microsoft Direct3D runtime calls the user-mode display driver's [**QueryEnd**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_queryend) function to transition a query operation to the "issued" state, the runtime can call **QueryGetData** to determine if the query operation is still in the "issued" state (DXGI_DDI_ERR_WASSTILLDRAWING) or has transitioned to the "signaled" state (S_OK). If the query operation is in the "signaled" state, **QueryGetData** can return the query data in the **pData** parameter; otherwise, **pData** is unchanged. The driver can call [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) to indicate the state of the query operation.

The runtime cannot call **QueryGetData** with a predicate that was created with D3D10_QUERY_MISCFLAG_PREDICATEHINT through a call to the [**SetPredication**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setpredication) function.

If a query operation handles work that still resides in partial command buffers, by default, the driver should terminate and submit the partial command buffers. However, the driver should not terminate and submit the buffers if the runtime specified the D3D10_DDI_GET_DATA_DO_NOT_FLUSH flag in the **Flags** parameter. If the runtime passed the D3D10_DDI_GET_DATA_DO_NOT_FLUSH flag in the **Flags** parameter and if the query operation handles work that still resides in partial command buffers, the driver can call [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) to set only the DXGI_DDI_ERR_WASSTILLDRAWING error code.

When the runtime calls **QueryGetData** to check for query completion, the driver can pass DXGI_DDI_ERR_WASSTILLDRAWING in a call to [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) to indicate that the query is not finished yet. The driver can also pass D3DDDIERR_DEVICEREMOVED in a call to **pfnSetErrorCb**. The Direct3D runtime will determine that any other errors are critical.

## See also

[**CheckCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounter)

[**D3D10DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[**QueryEnd**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_queryend)

[**SetPredication**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setpredication)

[**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)