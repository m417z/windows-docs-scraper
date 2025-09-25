## Description

The **IWiaImageFilter::FilterPreviewImage** method is called by the WIA Preview component, when an application calls the [**IWiaPreview::UpdatePreview**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiapreview-updatepreview) method.

## Parameters

### `lFlags`

### `pWiaChildItem2` [in]

Pointer to the item that the image process is to process. This item must be a child item of the item specified in the *pWiaItem2* parameter, which was passed into the [**IWiaImageFilter::InitializeFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nf-wia_lh-iwiaimagefilter-initializefilter) method.

### `InputImageExtents` [in]

Structure that contains the upper-left and lower-right coordinates of a rectangle that represents the boundaries of the preview image on the flatbed's platen. This is also the coordinates for the image data that is passed into the *pInputStream* parameter .

### `pInputStream` [in]

Pointer to the [**IStream**](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istream) preview image.

## Return value

Returns S_OK on success, or a standard COM error code on failure.

## Remarks

This method cannot be invoked directly by the application.