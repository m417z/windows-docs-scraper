# IShellImageData::NextPage

## Description

Switches to the next page of a multipage image. Any associated animations are reset.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The current page cannot be retrieved. |
| **OLE_E_ENUM_NOMORE** | No further pages are available, the image was not previously decoded, or the decode process failed. |