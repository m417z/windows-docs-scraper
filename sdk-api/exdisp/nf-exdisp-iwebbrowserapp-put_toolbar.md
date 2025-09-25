# IWebBrowserApp::put_ToolBar

## Description

Sets or gets whether toolbars for the object are visible.

This property is read/write.

## Parameters

## Remarks

When the IWebBrowser2::ToolBar property is set to FALSE, it is not equivalent to the "toolbar=no" feature of window.open. Instead, it turns off all user interface elements that can be considered toolbars, leaving Windows Internet Explorer in a blank state.

The WebBrowser object saves the value of this property, but otherwise ignores it.

## See also

[IWebBrowser2](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-iwebbrowser2)