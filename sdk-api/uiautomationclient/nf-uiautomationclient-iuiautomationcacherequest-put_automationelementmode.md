# IUIAutomationCacheRequest::put_AutomationElementMode

## Description

Indicates whether returned elements contain full references to the underlying UI, or only cached information.

This property is read/write.

## Parameters

## Remarks

[AutomationElementMode_Full](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-automationelementmode) is the default value, and specifies that returned elements contain a full reference to the underlying UI. [AutomationElementMode_None](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-automationelementmode) specifies that the returned elements have no reference to the underlying UI, and contain only cached information.

Certain operations on elements, including [GetCurrentPropertyValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcurrentpropertyvalue), and [SetFocus](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-setfocus), require a full reference; attempting to perform these on an element that has none results in an error.

Using [AutomationElementMode_None](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-automationelementmode) can be more efficient when only properties are needed, as it avoids the overhead involved in setting up full references.