# IUIAutomationRangeValuePattern::get_CachedSmallChange

## Description

Retrieves, from the cache, the value that is added to or subtracted from the value of the control when a small change is made, such as when an arrow key is pressed.

This property is read-only.

## Parameters

## Remarks

The SmallChange property can support a Not a Number (NaN) value. When retrieving this property, a client can use the [_isnan](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-6.0/aa298428(v=vs.60)) function to determine whether the property is a NaN value.

## See also

[IUIAutomationRangeValuePattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationrangevaluepattern)

[IUIAutomationRangeValuePattern::CachedLargeChange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationrangevaluepattern-get_cachedlargechange)