# CInstance::GetCHString

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetCHString** method retrieves a string property.

## Parameters

### `name`

Name of the string property retrieved.

### `str` [ref]

Buffer to receive the string property.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if an attempt was made to retrieve a nonstring property or a nonexistent property. More information is available in the log file, Framework.log.