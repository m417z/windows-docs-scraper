## Description

Called by the WIA mini-driver to obtain a stream for the current data transfer (download or upload).

## Parameters

### `lFlags` [in]

Represents flag bits. This parameter is unused and should always be set to zero (0) by the caller.

### `bstrItemName` [in]

The name of the item that will perform the data transfer.

For more information, see [WIA_IPA_ITEM_NAME](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-item-name).

### `bstrFullItemName` [in]

The full name of the item that will perform the data transfer.

For more information, see [WIA_IPA_FULL_ITEM_NAME](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-full-item-name).

### `ppIStream` [out]

A pointer to an **IStream** object.

## Return value

This method returns **S_OK** when the call is successful. Otherwise it returns an appropriate **HRESULT** error code.

## Remarks

When the client requests to skip the data transfer, the **GetNextStream** method returns **WIA_STATUS_SKIP_ITEM**. The WIA mini-driver must skip the current image transfer and continue with the next image transfer, if any. For example, for a download transfer, finish scanning the current image and then discard the image data.

When the current transfer sequence is cancelled, the **GetNextStream** method returns **S_FALSE**.

## See also

[Cancellation of Data Transfers](https://learn.microsoft.com/windows-hardware/drivers/image/cancellation-of-data-transfers-in-windows-vista)

[Data Transfer Between Legacy Application and Windows Driver](https://learn.microsoft.com/windows-hardware/drivers/image/data-transfer-between-legacy-application-and-windows-vista-driver)

[IWiaMiniDrvTransferCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrvtransfercallback)

[WIA_IPA_FULL_ITEM_NAME](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-full-item-name)

[WIA_IPA_ITEM_NAME](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ipa-item-name)