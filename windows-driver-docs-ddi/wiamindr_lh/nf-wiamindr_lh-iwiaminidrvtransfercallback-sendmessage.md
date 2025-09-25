## Description

Periodically called by the WIA mini-driver during a data transfer, to update the WIA application client about the progress and status of the transfer.

For more information about the progress data that is transferred, see [WiaTransferParams](https://learn.microsoft.com/windows/win32/wia/-wia-wiatransferparams).

## Parameters

### `lFlags` [in]

Represents flag bits. This parameter is unused and should always be set to zero (0) by the caller.

### `pWiaTransferParams` [in]

Pointer to a **WiaTransferParams** object.

## Return value

This method returns **S_OK** when the call is successful. Otherwise it returns an appropriate **HRESULT** error code.

## Remarks

When the current transfer sequence is cancelled, the **SendMessage** method returns S_FALSE.

## See also

[Cancellation of Data Transfers](https://learn.microsoft.com/windows-hardware/drivers/image/cancellation-of-data-transfers-in-windows-vista)

[IWiaMiniDrvTransferCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrvtransfercallback)

[WiaTransferParams](https://learn.microsoft.com/windows/win32/wia/-wia-wiatransferparams)