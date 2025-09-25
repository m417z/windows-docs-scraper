# IWebApplicationHost::Refresh

## Description

Refreshes the current document without sending a 'Pragma:no-cache' HTTP header to the server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use this method when the currently executing code is outside of the activation path. If the code is executing inside the activation path, use [IWebApplicationActivation::CancelPendingActivation](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nf-webapplication-iwebapplicationactivation-cancelpendingactivation) instead.

## See also

[IWebApplicationHost](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationhost)