# PFND3D10DDI_SETPREDICATION callback function

## Description

The *SetPredication* function specifies whether rendering and resource-manipulation commands that follow are actually performed.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hQuery* [in]

A handle to the query object to set as a predicate. Setting *hQuery* to **NULL** indicates "no predication". If *hQuery* is set to **NULL**, the driver ignores the value in the *PredicateValue* parameter; however, the driver should store the predicate value for subsequent requests for the value.

### `unnamedParam3`

*PredicateValue* [in]

A Boolean value to compare with query data. If the query data is equal to the predicate value, the following rendering and resource manipulation commands are not performed.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

 Some predicates are only hints; therefore, they might not actually prevent operations from being performed. The Microsoft Direct3D runtime primarily calls *SetPredication* to let applications issue graphics commands without taking the performance hit of spinning and waiting for a call to the [QueryGetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata) function to return. Therefore, predication can occur even if *QueryGetData* returns S_FALSE. In other words, an application can also use predication as a fallback if *QueryGetData* possibly returns S_FALSE. If *QueryGetData* returns S_OK, the application can skip calling the graphics commands manually with its own application logic.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *SetPredication* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)