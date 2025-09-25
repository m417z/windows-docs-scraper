## Description

The **IWiaTransferCallback::TransferCallback** method is implemented by an image processing filter. It is called by the WIA service as a result of an application calling **IWiaTransfer::Download** or the preview component's **IWiaPreview::GetNewPreview**.

## Parameters

### `lFlags` [in]

Currently unused. Should be set to zero.

### `pWiaTransferParams` [in]

Specifies a pointer to a [**WiaTransferParams**](https://learn.microsoft.com/windows/win32/wia/-wia-wiatransferparams) structure.

## Return value

Returns S_OK if successful, or a standard COM error value otherwise.

## Remarks

An image processing filter's implementation of **IWiaTransferCallback::TransferCallback** method is called during image acquisition, when the WIA mini-driver asks for the destination stream from the client and when the mini-driver sends progress messages back to the application.

An image processing filter's **IWiaTransferCallback::TransferCallback** method must delegate to the application callback's **IWiaTransferCallback::TransferCallback** method. In many cases the image processing filter's **IWiaTransferCallback::TransferCallback** implementation will also have to modify the *ulBytesWrittenToCurrentStream* and possibly also the *lPercentComplete* values in the WiaTransferParams structure. *ulBytesWrittenToCurrentStream* must be modified if the image processing filter has to buffer image data between calls to its Write method before it writes the data to the application provided stream. This would, for example, be needed if deskewing and/or rotation if is being performed. If no rotation or deskewing is needed the filter should preferably work on bands of data. *lPercentComplete* does not necessarily need to be modified, however, since this parameter indicates the percentage of total transfer time. This member can for example be used by a progress bar in an application. Note that the image processing filter should not modify the lMessage member of the structure. **IWiaTransferCallback::TransferCallback** also should not "swallow" any messages it receives even if it performs buffering, rather it should modify the *ulBytesWrittenToCurrentStream* member.

This method is not called by the preview component during **IWiaPreview::UpdatePreview**.