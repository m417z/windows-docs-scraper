# PFND3DDDI_GETINFO callback function

## Description

The *GetInfo* function retrieves information about the specified display device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*DevInfoID*

An identifier for the type of device information to retrieve.

### `unnamedParam3`

*pDevInfoStruct*

A pointer to a buffer of the type that *DevInfoID* specifies that receives information about the device.

### `DevInfoSize`

The size, in bytes, of the buffer that is supplied by *pDevInfoStruct*.

## Return value

*GetInfo* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The device information is successfully retrieved.|
|E_NOTIMPL|The driver does not support the requested type of device information.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

## Remarks

The Microsoft DirectX 7 and DirectX 8 runtimes call the *GetInfo* function to query a user-mode display driver for additional device information.

The Direct3D 8 runtime sets the D3DDDIDEVINFOID_VCACHE flag in the *DevInfoID* parameter and specifies an empty [D3DDDIDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddidevinfo_vcache) structure in the *pDevInfoStruct* parameter to query the user-mode display driver's support for vertex cache.

## See also

[D3DDDIDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddidevinfo_vcache)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)