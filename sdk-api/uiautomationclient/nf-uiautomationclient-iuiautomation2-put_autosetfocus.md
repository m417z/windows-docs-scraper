# IUIAutomation2::put_AutoSetFocus

## Description

Specifies whether calls to UI Automation control pattern methods automatically set focus to the target element.

This property is read/write.

## Parameters

## Remarks

 By default, most UI Automation methods that perform an action on an element, such as [IUIAutomationInvokePattern::Invoke](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationinvokepattern-invoke) and [IUIAutomationValuePattern::SetValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationvaluepattern-setvalue), set focus to the element before performing the action. For most applications, setting the focus results in a more consistent user experience. In situations where setting the focus would be disruptive, such as automating a drop-down menu, you can set **AutoSetFocus** to FALSE to prevent UI Automation methods from setting the focus.

## See also

[IUIAutomation2](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation2)