# IExtractImage::Extract

## Description

Requests an image from an object, such as an item in a Shell folder.

## Parameters

### `phBmpThumbnail` [out]

Type: **HBITMAP***

The buffer to hold the bitmapped image.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error code otherwise.

## Remarks

You must call [IExtractImage::GetLocation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iextractimage-getlocation) prior to calling **Extract**.