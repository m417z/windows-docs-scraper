# CHString::UnlockBuffer

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **UnlockBuffer** method unlocks the buffer that was previously secured by calling [LockBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-lockbuffer) and resets the reference count to 1.

## Remarks

The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) destructor implies **UnlockBuffer** to ensure that you do not leave the buffer locked when the destructor is called.

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::LockBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-lockbuffer)