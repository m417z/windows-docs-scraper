# IWiaVideo::TakePicture

## Description

The **IWiaVideo::TakePicture** method extracts a still image from the video stream, and saves the image as a JPEG file.

## Parameters

### `pbstrNewImageFilename` [out]

Type: **BSTR***

Receives the full path and filename of the JPEG file that this method creates.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The path and directory where the image file is saved are specified by the [IWiaVideo::ImagesDirectory](https://learn.microsoft.com/windows/desktop/api/wiavideo/nf-wiavideo-iwiavideo-get_imagesdirectory) property.