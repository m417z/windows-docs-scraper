# IShellImageData::ReplaceFrame

## Description

Replaces the current frame with a new image.

## Parameters

### `pImg` [in]

Type: **Image***

The address of the new image.

## Return value

Type: **HRESULT**

Always returns S_OK.

## Remarks

You should also call [IShellImageData::DiscardEdit](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-discardedit) to ensure that any edited properties of the original image are not retained.

In the case of a multiframed image such as a .gif file, the current frame is replaced. In the case of non-multiframed images such a .jpg file, the entire image is replaced.

Replacing a frame in an animated .gif file causes that file's animation to no longer be functional. Replacing a frame in a Tagged Image File Format (TIFF) file could cause that file to lose pages, particularly if the TIFF frame's image is not the same size as the original. If possible, you should always replace a TIFF frame's image with a TIFF of the same size.

The [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) implementation takes ownership of the image named in *pImg* and the caller should not try to use it after calling **IShellImageData::ReplaceFrame**.