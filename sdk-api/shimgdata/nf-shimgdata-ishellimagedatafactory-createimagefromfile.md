# IShellImageDataFactory::CreateImageFromFile

## Description

Creates an instance of the [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) interface based on a given file.

## Parameters

### `pszPath` [in]

Type: **LPCWSTR**

The path of the file containing the image. If this parameter is **NULL**, an unhandled exception results.

### `ppshimg` [out]

Type: **[IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata)****

The address of a pointer to an instance of [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata).

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The internal object cannot be instantiated. |
| **E_NOINTERFACE** | The internal object does not support the [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) or [IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile) interfaces. |
| **E_POINTER** | The *ppshimg* parameter is **NULL**. |

## Remarks

An access violation occurs if *pszPath* is **NULL**.