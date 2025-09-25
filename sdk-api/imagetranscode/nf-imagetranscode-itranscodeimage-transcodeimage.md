# ITranscodeImage::TranscodeImage

## Description

Converts an image to JPEG or bitmap (BMP) image format.

## Parameters

### `pShellItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

The Shell Item for the image to convert.

### `uiMaxWidth`

Type: **UINT**

The requested height in pixels. Should be less than or equal to the actual height of the original image. See Remarks.

### `uiMaxHeight`

Type: **UINT**

The requested width in pixels. Should be less than or equal to the actual width of the original image. See Remarks.

### `flags`

Type: **TI_FLAGS**

One of the following flags.

#### TI_BITMAP

Convert the image to BMP format.

#### TI_JPEG

Convert the image to JPEG format.

### `pvImage`

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A stream to receive the converted image. The stream must be created by the calling code prior to calling **TranscodeImage**.

### `puiWidth` [out, optional]

Type: **UINT***

The actual width of the converted image.

### `puiHeight` [out, optional]

Type: **UINT***

The actual height of the converted image.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The aspect ratio of the original image is preserved.
The new image is resized so that it will fit into a box of width *uiMaxWidth* and height *uiMaxHeight*.

The image size will not be changed if the original image already fits in this bounding box.

If both uiMaxWidth and uiMaxHeight are zero, the returned image will be the same size as the original.