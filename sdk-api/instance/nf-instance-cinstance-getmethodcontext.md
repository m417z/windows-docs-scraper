# CInstance::GetMethodContext

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetMethodContext** method returns a pointer to a **MethodContext** object.

## Return value

Returns a pointer to the current **MethodContext** object.

## Remarks

Framework providers should not release the **MethodContext** pointer returned by this function.