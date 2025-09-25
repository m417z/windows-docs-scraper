# PFND3D10DDI_QUERYEND callback function

## Description

The *QueryEnd* function marks the end of a sequence of graphics commands for a query and transitions the query to the "issued" state.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hQuery* [in]

A handle to the query object to end.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

If the driver supports the [QueryBegin](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querybegin) function for a query operation, and if the Microsoft Direct3D runtime calls *QueryEnd* without call *QueryBegin*, the call is equivalent to first calling *QueryBegin* and then calling *QueryEnd* immediately afterward. In addition, the runtime cannot call *QueryEnd* on a predicate that is currently bound to the pipeline through a call to the [SetPredication](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setpredication) function.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *QueryEnd* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[QueryBegin](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querybegin)

[SetPredication](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_setpredication)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)