# IShellImageDataFactory::CreateIShellImageData

## Description

Creates an instance of the [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) interface.

## Parameters

### `ppshimg` [out]

Type: **[IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata)****

The address of a pointer to an instance of [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata).

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The internal object cannot be instantiated. |
| **E_NOINTERFACE** | The internal object does not support [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata). |
| **E_POINTER** | The *ppshimg* parameter is **NULL**. |