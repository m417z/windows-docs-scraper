# IWebApplicationNavigationEvents::BeforeNavigate

## Description

Fired before navigate occurs in the given host (window or frameset element).

## Parameters

### `htmlWindow` [in]

Type: **[IHTMLWindow2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa741505(v=vs.85))***

The window or frame in which the navigation is about occur.

### `url` [in]

Type: **LPCWSTR**

The URL to navigate to.

### `navigationFlags` [in]

Type: **DWORD**

Flags related to the current navigation.

### `targetFrameName` [in]

Type: **LPCWSTR**

The name of the frame in which the navigation is about to occur. The value is **null** if no named frame is targeted.

## Return value

Type: **HRESULT**

Ignored by the host. If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWebApplicationNavigationEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationnavigationevents)