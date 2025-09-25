# CInstance::IsNull

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **IsNull** method determines if the value of a particular property is **NULL**.

## Parameters

### `name`

Name of property that is checked.

## Return value

Returns **TRUE** if the property specified by *name* is **NULL** and **FALSE** if it is not.