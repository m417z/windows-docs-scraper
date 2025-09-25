# CInstance::Getbool

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **Getbool** method retrieves a Boolean property.

## Parameters

### `name`

Name of the property retrieved.

### `b` [ref]

Buffer to receive the Boolean property.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if an attempt was made to retrieve a non-Boolean property or a nonexistent property. More information is available in the log file, Framework.log.