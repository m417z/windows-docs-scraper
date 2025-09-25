## Description

The **IWiaTransferCallback::GetNextStream** method is implemented by an image processing filter. It is called by the WIA service as a result of an application calling [**IWiaTransfer::Download**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiatransfer-download) or the preview component's [**IWiaPreview::GetNewPreview**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiapreview-getnewpreview).

## Parameters

### `lFlags` [in]

Reserved, set to zero.

### `bstrItemName` [in]

Specifies a string containing the name of the item.

### `bstrFullItemName` [in]

Specifies a string containing the full name of the item.

### `ppDestination` [out]

Specifies a pointer to the output stream.

## Return value

Returns S_OK if successful, or a standard COM error value otherwise.

## Remarks

An image processing filter's implementation of **IWiaTransferCallback::GetNextStream** and **IWiaTransferCallback::TransferCallback** are called during image acquisition, when the WIA mini-driver asks for the destination stream from the client and when the mini-driver sends progress messages back to the application.

An image processing filter's implementation of **IWiaTransferCallback::GetNextStream** must delegate to the application's **IWiaTransferCallback::GetNextStream** method. The image processing filter then uses the stream returned by the application callback's **IWiaTransferCallback::GetNextStream** implementation to create its own stream (the "filtering stream") that it passes back to the WIA service.

In its **IWiaTransferCallback::GetNextStream** implementation, the image processing filter should read which properties are needed for its image processing from the item for which the image is being acquired. The filter must not read the properties directly from the *pWiaItem2* passed into [**IWiaImageFilter::InitializeFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nf-wia_lh-iwiaimagefilter-initializefilter); rather it must call [**IWiaItem2::FindItemByName**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2-finditembyname) on this WIA item to obtain the actual WIA item. The reason is that during a folder transfer the images acquired correspond to the child items of *pWiaItem2* rather than to *pWiaItem2* itself.

This method is not called by the preview component during [**IWiaPreview::UpdatePreview**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiapreview-updatepreview).

## See also

[**IWiaImageFilter::InitializeFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nf-wia_lh-iwiaimagefilter-initializefilter)

[**IWiaTransferCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwiatransfercallback)