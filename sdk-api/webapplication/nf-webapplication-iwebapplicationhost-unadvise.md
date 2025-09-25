# IWebApplicationHost::Unadvise

## Description

Removes a previously established connection.

## Parameters

### `cookie` [in]

Type: **DWORD**

A connection token previously returned from the [Advise](https://learn.microsoft.com/previous-versions/windows/desktop/debug_wwahost/iwebapplicationhost-advise) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWebApplicationHost](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationhost)

[IWebApplicationHost::Advise](https://learn.microsoft.com/previous-versions/windows/desktop/debug_wwahost/iwebapplicationhost-advise)