# PFND3DDDI_GETRESOURCEPRESENTPRIVATEDRIVERDATACB callback function

## Description

**pfnGetResourcePresentPrivateDriverDataCb** is used to query the resource private data, which is associated with the resource during Present.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDI_GETRESOURCEPRESENTPRIVATEDRIVERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_getresourcepresentprivatedriverdata) structure that describes the operation to perform and contains the results.

## Return value

|Return value|Description|
|--- |--- |
|S_OK|The operation completed successfully.|
|STATUS_INVALID_BUFFER_SIZE|The value of D3DDDI_GETRESOURCEPRESENTPRIVATEDRIVERDATA::PrivateDriverDataSize was zero or was insufficient to hold the data. When control returns to the caller, PrivateDriverDataSize will contain the required buffer size.|

This method may return other **HRESULT** values.