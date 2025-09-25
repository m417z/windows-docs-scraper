# CHString::LockBuffer

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **LockBuffer** method locks a string in the buffer.

## Return value

Returns a pointer to a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) object or a **NULL**-terminated string.

## Remarks

By calling **LockBuffer**, you create a copy of the string and then set the reference count to -1.

When the reference count is set to -1, the string in the buffer is considered to be in a locked state, which protects the string in the following two ways:

* No other string can get a reference to the data in the locked string, even if that string is assigned to the locked string.
* The locked string never references another string, even if that other string is copied to the locked string.

By locking the string in the buffer, you ensure that the string's exclusive hold on the buffer remains intact.

After you have finished with **LockBuffer**, call [UnlockBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-unlockbuffer) to reset the reference count to 1 (one).

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::UnlockBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-unlockbuffer)