# CInstance::SetByte

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetByte** method sets a **BYTE** property.

## Parameters

### `name`

Name of the **BYTE** property that is set.

### `b`

Value assigned to the **BYTE** property.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if an attempt was made to set a nonexistent property or a property that is not **BYTE** compatible. More information is available in the log file, Framework.log.