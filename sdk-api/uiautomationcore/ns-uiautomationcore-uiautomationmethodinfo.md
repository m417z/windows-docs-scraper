# UIAutomationMethodInfo structure

## Description

Contains information about a method that is supported by a custom control pattern.

## Members

### `pProgrammaticName`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the method (a non-localizable string).

### `doSetFocus`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if UI Automation should set the focus on the object before calling the method; otherwise **FALSE**.

### `cInParameters`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of [in] parameters, which are always first in the **pParameterTypes** array.

### `cOutParameters`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The count of [out] parameters, which always follow the [in] parameters in the **pParameterTypes** array.

### `pParameterTypes`

Type: **[UIAutomationType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype)***

A pointer to an array of values indicating the data types of the parameters of the method. The data types of the In parameters should be first, followed by those of the Out parameters.

### `pParameterNames`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to an array containing the parameter names (non-localizable strings).

## See also

[Custom Properties, Events, and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-custompropertieseventscontrolpatterns)

[UIAutomationPatternInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiautomationpatterninfo)