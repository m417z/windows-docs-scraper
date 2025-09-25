# ExtendedProperty structure

## Description

Contains information about an extended property.

## Members

### `PropertyName`

Type: **BSTR**

A localized string that contains the name of the extended property.

### `PropertyValue`

Type: **BSTR**

A string that represents the value of the extended property. This string should be localized, if appropriate.

## Remarks

This structure is used by the [IUIAutomationStylesPattern::GetCachedExtendedPropertiesArray](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437294(v=vs.85)) and [GetCurrentExtendedPropertiesArray](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh437295(v=vs.85)) methods.