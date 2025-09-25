# IShellImageData::PrevPage

## Description

Switches to the previous page of a multipage image. Any associated animations are reset.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The current frame cannot be retrieved. |
| **OLE_E_ENUM_NOMORE** | No previous pages are available, the image was not previously decoded, or the decode process failed. |