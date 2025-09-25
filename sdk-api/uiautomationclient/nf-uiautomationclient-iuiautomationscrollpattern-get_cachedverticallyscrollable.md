# IUIAutomationScrollPattern::get_CachedVerticallyScrollable

## Description

Retrieves a cached value that indicates whether the element can scroll vertically.

This property is read-only.

## Parameters

## Remarks

This property can be dynamic. For example, the content area of the element might not be larger than the current viewable area, meaning that the property is **FALSE**. However, resizing the element or adding child items can increase the bounds of the content area beyond the viewable area, making the property **TRUE**.

## See also

[IUIAutomationScrollPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationscrollpattern)

[IUIAutomationScrollPattern::CachedHorizontallyScrollable](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationscrollpattern-get_cachedhorizontallyscrollable)