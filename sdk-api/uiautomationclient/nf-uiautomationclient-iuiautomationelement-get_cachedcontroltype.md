# IUIAutomationElement::get_CachedControlType

## Description

Retrieves a cached value that indicates the control type of the element.

This property is read-only.

## Parameters

## Remarks

Control types describe a known interaction model for UI Automation elements without relying on a localized control type or combination of complex logic rules. This property cannot change at run time unless the control supports the [IUIAutomationMultipleViewPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationmultipleviewpattern) interface. An example is the Win32 ListView control, which can change from a data grid to a list, depending on the current view.

## See also

[Automation Element Property IDs](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-automation-element-propids)

[CurrentControlType](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-get_currentcontroltype)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

**Reference**