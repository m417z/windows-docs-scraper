# IWRdsProtocolConnectionCallback::RedrawWindow

## Description

Requests that the Remote Desktop Services service redraw the client window.

## Parameters

### `rect` [in, optional]

A [WRDS_SMALL_RECT](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_small_rect) structure that contains the x and y coordinates of the screen to redraw. A value of **NULL** requests that the entire screen be redrawn.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method is typically called after the [StopScreenUpdates](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnectioncallback-stopscreenupdates) method.

To avoid deadlocks when calling this method:

* Create a separate thread on which to make the call. Do not make the call from inside any protocol method that you are implementing.
* Do not block on this method before replying to another call by the Remote Desktop Services service.

## See also

[IWRdsProtocolConnectionCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnectioncallback)