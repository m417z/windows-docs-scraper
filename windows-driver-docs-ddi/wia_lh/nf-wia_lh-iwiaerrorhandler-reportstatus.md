## Description

The **ReportStatus** method displays information about an error or status during a transfer. In some cases this method allows the user to recover from an error.

## Parameters

### `lFlags` [in]

Currently unused. Should be set to zero.

### `hwndParent` [in]

Caller supplied handle of the window that should be used as the parent window for any dialog boxes. If this is set to **NULL**, no dialog boxes should be displayed.

### `pWiaItem2` [in]

Pointer to the[**IWiaItem2**](https://learn.microsoft.com/windows/win32/wia/-wia-iwiaitem2) item being transferred.

### `hrStatus` [in]

HRESULT variable that contains the status code received by the WIA transfer method, for example the [**IWiaDataCallback::BandedDataCallback**](https://learn.microsoft.com/windows/win32/api/wia_xp/nf-wia_xp-iwiadatacallback-bandeddatacallback) method.

### `lPercentComplete` [in]

Size of the data, in bytes, the *pbData* pointer refers to.

## Return value

Returns a standard COM error code if the error cannot be recovered from, or if the user chooses to abort the transfer in response to the displayed dialog box. There is additional information on the return values in the remarks section. Otherwise this method returns one of the following values:

| Return code | Description |
|---|---|
| **S_OK** | Appropriate action was taken to correct the error and the transfer can continue. |
| **S_FALSE** | No action was taken to handle the error or report status to the user. |

## Remarks

The COM proxy callback object calls the **WiaErrorHandler::ReportStatus** method when the driver sends an IT_MSG_DEVICE_STATUS message to the [**IWiaDataCallback::BandedDataCallback**](https://learn.microsoft.com/windows/win32/api/wia_xp/nf-wia_xp-iwiadatacallback-bandeddatacallback) method. The dialog box that this method displays provides the user with error or status information and possibly gives an opportunity to recover from the error and continue the transfer. The UI should provide only an informational dialog box and a chance to cancel the transfer if the HRESULT is SEVERITY_SUCCESS.

A driver that implements this method, should display a modal dialog box, owned by *hwndParent*, in response to a value of *hrStatus* for which **FAILED**(*hrStatus*) evaluates to **TRUE**. If **FAILED**(*hrStatus*) evaluates to **FALSE**, the value in *hrStatus* represents a nonfatal delay, and the dialog box displayed should be modeless. The dialog box should be removed when the status of the transfer changes. An error handler should return S_FALSE for unknown values of *hrStatus*.

The *hrStatus* parameter is set to WIA_STATUS_TRANSFER_BEGIN to inform the handler that a transfer has started. It is set to WIA_STATUS_TRANSFER_END when the transfer is complete.

If *hrStatus* is S_OK, the data transfer has resumed and no delay or error is currently in effect.

## See also

[**IWiaErrorHandler**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwiaerrorhandler)

[**IWiaErrorHandler::GetStatusDescription**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nf-wia_lh-iwiaerrorhandler-getstatusdescription)