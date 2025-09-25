# IShellImageDataFactory::CreateImageFromStream

## Description

Creates an instance of the [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) interface based on a given file stream.

## Parameters

### `pStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the image stream.

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

If *pStream* is **NULL** or an invalid pointer, later calls to [Decode](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-decode) will cause an access violation.