# IWebApplicationNavigationEvents::NavigateComplete

## Description

Fired when the document being navigated to becomes visible and enters the navigation stack.

## Parameters

### `htmlWindow` [in]

Type: **[IHTMLWindow2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa741505(v=vs.85))***

The window or frame in which the navigation is occurred.

### `url` [in]

Type: **LPCWSTR**

The URL which was navigated to

## Return value

Type: **HRESULT**

Ignored by the host. If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWebApplicationNavigationEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationnavigationevents)