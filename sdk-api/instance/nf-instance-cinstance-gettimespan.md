# CInstance::GetTimeSpan

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetTimeSpan** method retrieves a property that represents a WMI time span.

## Parameters

### `name`

Name of the time span property retrieved.

### `wbemtimespan` [ref]

Buffer to receive the time span property.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if the supplied time span type is not valid for the property being returned or an attempt is made to retrieve a nonexistent property. More information is available in the log file, Framework.log.