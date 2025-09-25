# CInstance::GetStatus

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetStatus** method determines whether a property exists and, if so, determines its type.

## Parameters

### `name`

Name of the property to verify.

### `a_Exists` [ref]

**TRUE** if property exists and **FALSE** if the property does not exist.

### `a_VarType`

Type of property.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** otherwise.