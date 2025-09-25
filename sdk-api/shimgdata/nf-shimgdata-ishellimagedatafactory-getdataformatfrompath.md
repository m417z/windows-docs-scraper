# IShellImageDataFactory::GetDataFormatFromPath

## Description

Determines a file's format based on its extension.

## Parameters

### `pszPath` [in]

Type: **LPCWSTR**

A path to the file.

### `pDataFormat` [out]

Type: **GUID***

A pointer to a GUID identifying the image format of the file.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The *pszPath* parameter is **NULL**, the file name extension does not correspond to any defined GDI+ decoder, or an internal error has occurred. In any of these cases, *pDataFormat* is set to GUID_NULL. |
| **E_OUTOFMEMORY** | The internal object cannot be instantiated. |

## Remarks

**IShellImageDataFactory::GetDataFormatFromPath** should only be used to determine whether data can be saved to a particular format on the current system.