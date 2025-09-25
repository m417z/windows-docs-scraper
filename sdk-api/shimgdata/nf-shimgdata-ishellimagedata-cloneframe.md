# IShellImageData::CloneFrame

## Description

Retrieves a clone of the current image or frame.

## Parameters

### `ppImg` [in, out]

Type: **Image****

The address that receives a pointer to the clone image. If this parameter is **NULL** on entry, an unhandled exception results.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The *ppImg* parameter is **NULL** on entry or the image cannot be cloned. In the latter case, *ppImg* is set to **NULL**. |

## Remarks

In the case of a multiframed image such as a .gif file, the current frame is cloned. In the case of non-multiframed images such a .jpg file, the entire image is cloned.