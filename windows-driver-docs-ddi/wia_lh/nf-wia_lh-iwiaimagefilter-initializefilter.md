## Description

The **IWiaImageFilter::InitializeFilter** method stores the references to *pWiaItem2* and *pWiaTransferCallback* parameters passed into the method.

## Parameters

### `pWiaItem2` [in]

Points to the [**IWiaItem2**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2) item that the image acquisition was initiated for by the application. In the case of [**IWiaTransfer::Download**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiatransfer-download), it is the WIA item from which we obtained the [**IWiaTransfer**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiatransfer) interface, and in the case of the Preview component, it is the item that we pass into the [**IWiaPreview::GetNewPreview**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiapreview-getnewpreview) method.

### `pWiaTransferCallback` [in]

Points to a [**IWiaTransferCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwiatransfercallback) interface. The **IWiaTransferCallback** interface is the application's callback interface, which is passed to **IWiaTransfer::Download** and **IWiaPreview::GetNewPreview**.

## Return value

Returns S_OK on success, or a standard COM error code on failure.

## Remarks

This method is called by the COM proxy object before the download call reaches the WIA service. This happens in two cases: when an application calls **IWiaTransfer::Download** method and when an application calls the **IWiaPreview::GetNewPreview** method.

All that **IWiaImageFilter::InitializeFilter** is required to do is to store the references to *pWiaItem2* and *pWiaTransferCallback* that are passed into it. These interface pointers should be stored as member variables in this method and **AddRef** should be called for each interface pointer. These two interface pointers are needed in the filter's implementation of [**IWiaTransferCallback::TransferCallback**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiatransfercallback-transfercallback) and [**IWiaTransferCallback::GetNextStream**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nf-wia_lh-iwiatransfercallback-getnextstream) methods.

This method cannot be invoked directly by the application.

## See also

[**IWiaImageFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwiaimagefilter)

[**IWiaItem2**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2)

[**IWiaPreview::GetNewPreview**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiapreview-getnewpreview)

[**IWiaTransferCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwiatransfercallback)

[**IWiaTransfer::Download**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiatransfer-download)