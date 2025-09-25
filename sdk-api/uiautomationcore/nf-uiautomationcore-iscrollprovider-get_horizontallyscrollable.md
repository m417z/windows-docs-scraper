# IScrollProvider::get_HorizontallyScrollable

## Description

Indicates whether the control can scroll horizontally.

This property is read-only.

## Parameters

## Remarks

This property can be dynamic. For example, the content area of the control
might not be larger than the current viewable area, meaning **IScrollProvider::HorizontallyScrollable**
is **FALSE**. However, either resizing the control or adding child items may increase the bounds of the
content area beyond the viewable area, meaning **IScrollProvider::HorizontallyScrollable** is **TRUE**.

## See also

[IScrollProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iscrollprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)