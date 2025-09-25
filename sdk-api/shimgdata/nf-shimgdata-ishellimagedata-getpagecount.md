# IShellImageData::GetPageCount

## Description

Gets the number of pages in a multipage image.

## Parameters

### `pcPages` [out]

Type: **ULONG***

A pointer to the page count. This value is valid only when the method returns S_OK.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image has not been decoded or the decoding process failed. |

## Remarks

If the image is not a multipage image, such as a .jpg file, the method returns S_OK with a page count of 1.