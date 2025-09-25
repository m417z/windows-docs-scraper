# UIAutomationPatternInfo structure

## Description

Contains information about a custom control pattern.

## Members

### `guid`

Type: **GUID**

The unique identifier of the control pattern.

### `pProgrammaticName`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the control pattern (a non-localizable string).

### `providerInterfaceId`

Type: **GUID**

The unique identifier of the provider interface for the control pattern.

### `clientInterfaceId`

Type: **GUID**

The unique identifier of the client interface for the control pattern.

### `cProperties`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of elements in **pProperties**.

### `pProperties`

Type: **[UIAutomationPropertyInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiautomationpropertyinfo)***

A pointer to an array of structures describing properties available on the control pattern.

### `cMethods`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of elements in **pMethods**.

### `pMethods`

Type: **[UIAutomationMethodInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiautomationmethodinfo)***

A pointer to an array of structures describing methods available on the control pattern.

### `cEvents`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of elements in **pEvents**.

### `pEvents`

Type: **[UIAutomationEventInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiautomationeventinfo)***

A pointer to an array of structures describing events available on the control pattern.

### `pPatternHandler`

Type: **[IUIAutomationPatternHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iuiautomationpatternhandler)***

A pointer to the object that makes the control pattern available to clients.

## See also

[Custom Properties, Events, and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-custompropertieseventscontrolpatterns)

[RegisterPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-iuiautomationregistrar-registerpattern)