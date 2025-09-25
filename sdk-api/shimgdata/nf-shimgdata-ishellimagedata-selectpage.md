# IShellImageData::SelectPage

## Description

Selects a specified page in a multipage image.

## Parameters

### `iPage` [in]

Type: **ULONG**

The page number of the page to select.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The current page cannot be retrieved, the image has not been decoded, or the decoding process failed. |
| **OLE_E_ENUM_NOMORE** | The specified page number does not exist. |