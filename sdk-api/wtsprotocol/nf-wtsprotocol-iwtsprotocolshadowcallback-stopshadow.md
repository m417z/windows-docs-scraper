# IWTSProtocolShadowCallback::StopShadow

## Description

[**IWTSProtocolShadowCallback::StopShadow** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolShadowCallback::StopShadow](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolshadowcallback-stopshadow).]

Instructs the Remote Desktop Services service to stop shadowing a target. This method is called in response to a call of [DoTarget](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolshadowconnection-dotarget) by the shadow client.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWTSProtocolShadowCallback](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolshadowcallback)