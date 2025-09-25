# Provider::SetCreationClassName

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetCreationClassName** method sets the **CreationClassName** string property, if any, of the given instance to the name of this provider.

## Parameters

### `pInstance`

Pointer to the affected instance.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if it was unsuccessful.

## Remarks

The **SetCreationClassName** method sets the value of the **CreateClassName** property to the name of the current class. Not all classes have a **CreationClassName** property.