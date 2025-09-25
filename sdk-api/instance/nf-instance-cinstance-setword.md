# CInstance::SetWORD

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetWORD** method sets a **WORD** property.

## Parameters

### `name`

Name of the **WORD** property that is set.

### `w`

Value assigned to the **WORD** property.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if an attempt was made to set a nonexistent or non-**WORD** property. More information is available in the log file, Framework.log.