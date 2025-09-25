# CHString::AllocSysString

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **AllocSysString** method allocates a new **BSTR** string that is Automation compatible. It then copies the contents of the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string into it, including the terminating **NULL** character.

## Return value

If the **AllocSysString** method is successful, it points to the newly allocated string.