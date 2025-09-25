# IWebBrowserApp::get_HWND

## Description

Gets the handle of the Windows Internet Explorer main window.

This property is read-only.

## Parameters

## Remarks

Internet Explorer 7. With the introduction of tabbed browsing, the return value of this method can be ambiguous. To alleviate confusion and maintain the highest level of compatibility with existing applications, this method returns a handle to the top-level window frame, not the currently selected tab.

## See also

[IWebBrowser2](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-iwebbrowser2)