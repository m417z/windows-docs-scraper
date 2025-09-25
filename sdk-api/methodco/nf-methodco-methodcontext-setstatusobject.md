# MethodContext::SetStatusObject

## Description

[The [MethodContext](https://learn.microsoft.com/windows/desktop/api/methodco/nl-methodco-methodcontext) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **SetStatusObject** method sets an internal pointer to [IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) information. WMI does not implement any functionality based on the pointer.

## Parameters

### `pObj`

A pointer to [IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) information.

## Return value

**TRUE** if the call method call was successful. **FALSE** if the object has already been set.

## See also

[MethodContext](https://learn.microsoft.com/windows/desktop/api/methodco/nl-methodco-methodcontext)