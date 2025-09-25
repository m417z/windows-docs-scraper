# IWTSProtocolConnectionCallback::StopScreenUpdates

## Description

[**IWTSProtocolConnectionCallback::StopScreenUpdates** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnectionCallback::StopScreenUpdates](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnectioncallback-stopscreenupdates).]

Requests that the Remote Desktop Services service stop updating the client screen.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

To avoid deadlocks when calling this method:

* Create a separate thread on which to make the call. Do not make the call from inside of any protocol method that you are implementing.
* Do not block on this method before replying to another call by the Remote Desktop Services service.

## See also

[IWTSProtocolConnectionCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnectioncallback)