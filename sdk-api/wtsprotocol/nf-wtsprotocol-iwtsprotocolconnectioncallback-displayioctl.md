# IWTSProtocolConnectionCallback::DisplayIOCtl

## Description

[**IWTSProtocolConnectionCallback::DisplayIOCtl** is no longer available for use as of Windows Server 2012.]

Requests that the Remote Desktop Services service send data to the display driver loaded in the session.

## Parameters

### `DisplayIOCtl` [in, optional]

A [WTS_DISPLAY_IOCTL](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_display_ioctl) structure that contains data to be sent to the display driver loaded in the session.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

To avoid deadlocks when calling this method:

* Create a separate thread on which to make the call. Do not make the call from inside of any protocol method that you are implementing.
* Do not block on this method before replying to another call by the Remote Desktop Services service.

## See also

[IWTSProtocolConnectionCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnectioncallback)

[WTS_DISPLAY_IOCTL](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_display_ioctl)