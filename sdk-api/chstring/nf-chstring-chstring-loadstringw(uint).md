# CHString::LoadStringW(UINT)

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **LoadStringW** method reads a Windows string resource (identified by *nID*) into an existing [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) object.

## Parameters

### `nID`

Windows string resource identifier.

## Return value

If the **LoadStringW** method is successful, the resource string is loaded into the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) object, and the method returns a nonzero value. If the method is unsuccessful, it returns zero.