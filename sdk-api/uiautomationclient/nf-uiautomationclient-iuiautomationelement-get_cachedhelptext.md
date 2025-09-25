# IUIAutomationElement::get_CachedHelpText

## Description

Retrieves the cached help text for the element.

This property is read-only.

## Parameters

## Remarks

This information is typically obtained from ToolTips.

**Caution** Do not retrieve the **CachedHelpText** property from a control that is based on the SysListview32 class. Doing so could cause the system to become unstable and data to be lost. A client application can discover whether a control is based on SysListview32 by retrieving the [CachedClassName](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-get_cachedclassname) or [CurrentClassName](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-get_currentclassname) property from the control.

## See also

[Automation Element Property IDs](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-automation-element-propids)

[CurrentHelpText](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-get_currenthelptext)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

**Reference**