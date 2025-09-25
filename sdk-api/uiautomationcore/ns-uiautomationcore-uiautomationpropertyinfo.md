# UIAutomationPropertyInfo structure

## Description

Contains information about a custom property.

## Members

### `guid`

Type: **GUID**

The unique identifier of the property.

### `pProgrammaticName`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The programmatic name of the property (a non-localizable string).

### `type`

Type: **[UIAutomationType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype)**

A value from the [UIAutomationType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype) enumerated type indicating the data type of the property value.

## Remarks

A custom property must have one of the following data types specified by the [UIAutomationType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype) enumeration. No other data types are supported for custom properties. For more information, see [Custom Properties, Events, and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-custompropertieseventscontrolpatterns).

* [UIAutomationType_Bool](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype)
* [UIAutomationType_Double](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype)
* [UIAutomationType_Element](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype)
* [UIAutomationType_Int](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype)
* [UIAutomationType_Point](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype)
* [UIAutomationType_String](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-uiautomationtype)

## See also

[Custom Properties, Events, and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-custompropertieseventscontrolpatterns)

[RegisterProperty](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-iuiautomationregistrar-registerproperty)