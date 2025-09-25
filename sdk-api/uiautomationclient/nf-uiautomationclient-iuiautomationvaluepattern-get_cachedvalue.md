# IUIAutomationValuePattern::get_CachedValue

## Description

Retrieves the cached value of the element.

This property is read-only.

## Parameters

## Remarks

Single-line edit controls support programmatic access to their contents through [IUIAutomationValuePattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationvaluepattern). However, multiline edit controls do not support this control pattern, and their contents must be retrieved by using [IUIAutomationTextPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern).

This property does not support the retrieval of formatting information or substring values. [IUIAutomationTextPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern) must be used in these scenarios as well.

## See also

[IUIAutomationValuePattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationvaluepattern)