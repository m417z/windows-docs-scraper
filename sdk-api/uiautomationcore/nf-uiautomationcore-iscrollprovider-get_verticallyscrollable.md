# IScrollProvider::get_VerticallyScrollable

## Description

Indicates whether the control can scroll vertically.

This property is read-only.

## Parameters

## Remarks

This property can be dynamic. For example, the content area of the control
might not be larger than the viewable area, meaning **IScrollProvider::VerticallyScrollable**
is **FALSE**. However, resizing the control or adding child items may increase the bounds of the
content area beyond the viewable area, meaning that **IScrollProvider::VerticallyScrollable** is **TRUE**.

## See also

[IScrollProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iscrollprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)