# PFND3D10DDI_CHECKCOUNTER callback function

## Description

The **CheckCounter** function retrieves information that describes a counter.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*Query* [in]

A [D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query)-typed value that identifies the counter identifier that information is retrieved for.

### `unnamedParam3`

*pCounterType* [out]

A pointer to a variable that receives one of the following values from the D3D10DDI_COUNTER_TYPE enumeration that identifies the data type that the counter outputs.

|Value|Meaning|
|--|--|
|D3D10DDI_COUNTER_TYPE_FLOAT32|Single-precision float|
|D3D10DDI_COUNTER_TYPE_UINT16|16-bit value|
|D3D10DDI_COUNTER_TYPE_UINT32|32-bit value|
|D3D10DDI_COUNTER_TYPE_UINT64|64-bit value|

### `unnamedParam4`

*pDescription* [out]

A pointer that the driver returns a NULL-terminated string to that contains the description of what the counter identifier measures.

### `unnamedParam5`

*pActiveCounters* [out]

A pointer to a variable that receives the number of simultaneously active counters that are allocated for the creation of the counter identifier that *Query* identifies.

### `pNameLength` [in, out]

A pointer to a variable that receives the size, in bytes, of the NULL-terminated string that the *pName* parameter specifies.

### `unnamedParam7`

*pName* [out]

A pointer that the driver returns a NULL-terminated string to that contains the name of the counter identifier.

### `pUnitsLength` [in, out]

A pointer to a variable that receives the size, in bytes, of the NULL-terminated string that the *pUnits* parameter specifies.

### `unnamedParam9`

*pUnits* [out]

A pointer that the driver returns a NULL-terminated string to that contains the name of the units that the counter identifier measures.

### `pDescriptionLength` [in, out]

A pointer to a variable that receives the size, in bytes, of the NULL-terminated string that the *pDescription* parameter specifies.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver's **CheckCounter** function can call the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set the ERR_UNSUPPORTED error code if the *Query* parameter of **CheckCounter**specifies a well-known counter that the device does not support.

The driver must validate a device-dependent counter identifier to ensure the identifier is within range. The driver must also ensure that enough space exists to copy each counter string into each buffer that the Microsoft Direct3D runtime provides. The driver can call the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set the E_INVALIDARG error code if there is not enough space for any of the provided buffers.

The driver's **CheckCounter** function cannot call the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set the D3DDDIERR_DEVICEREMOVED error code because **CheckCounter** is a capability-check type of function. The driver must ensure that it has enough information after device creation to respond to a call to **CheckCounter**, even in the presence of D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[D3D10DDI_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10ddi_query)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)