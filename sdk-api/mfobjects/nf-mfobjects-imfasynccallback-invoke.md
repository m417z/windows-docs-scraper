# IMFAsyncCallback::Invoke

## Description

Called when an asynchronous operation is completed.

## Parameters

### `pAsyncResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass this pointer to the asynchronous **End...** method to complete the asynchronous call.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Within your implementation of **Invoke**, call the corresponding **End...** method.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Asynchronous Callback Methods](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-callback-methods)

[IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback)

[MFInvokeCallback](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfinvokecallback)