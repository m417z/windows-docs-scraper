# CInstance::SetVariant

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetVariant** method sets a **VARIANT** property.

## Parameters

### `name`

Name of the **VARIANT** property that is set.

### `variant` [ref]

Value assigned to the **VARIANT** property.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if the supplied variant type is not correct for the property being set. **SetVariant** also returns **FALSE** if an attempt is made to set a nonexistent property. More information is available in the log file, Framework.log.