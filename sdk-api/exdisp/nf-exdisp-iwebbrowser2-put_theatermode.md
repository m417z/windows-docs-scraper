# IWebBrowser2::put_TheaterMode

## Description

Sets or gets whether the object is in theater mode.

This property is read/write.

## Parameters

## Remarks

In theater mode, the object's main window fills the entire screen and displays a toolbar that has a minimal set of navigational buttons. A status bar is also provided in the upper-right corner of the screen. Explorer bars, such as History and Favorites , are displayed as an autohide pane on the left edge of the screen in theater mode.

Setting TheaterMode (even to VARIANT_FALSE) resets the values of the IWebBrowser2::AddressBar and IWebBrowser2::ToolBar properties to VARIANT_TRUE. Disable the address bar and toolbars after you set the TheaterMode property.

The WebBrowser object saves the value of this property, but otherwise ignores it.

## See also

[IWebBrowser2](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-iwebbrowser2)