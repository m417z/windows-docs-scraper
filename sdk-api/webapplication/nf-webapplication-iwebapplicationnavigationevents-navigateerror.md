# IWebApplicationNavigationEvents::NavigateError

## Description

Fired when a binding error occurs (window or frameset element).

## Parameters

### `htmlWindow` [in]

Type: **[IHTMLWindow2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa741505(v=vs.85))***

The window ro frame in which the navigation error occurred.

### `url` [in]

Type: **LPCWSTR**

The URL for which navigation failed.

### `targetFrameName` [in]

Type: **LPCWSTR**

The name of the frame in which the navigation error occurred. The value is **null** if no named frame was targeted.

### `statusCode` [in]

Type: **DWORD**

The error code. Could be a **HRESULT** or a HTTP status code.

## Return value

Type: **HRESULT**

Ignored by the host. If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWebApplicationNavigationEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationnavigationevents)