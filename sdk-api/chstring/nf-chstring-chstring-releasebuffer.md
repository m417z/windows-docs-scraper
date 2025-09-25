# CHString::ReleaseBuffer

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **ReleaseBuffer** method ends the use of a buffer allocated by [GetBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getbuffer).

## Parameters

### `nNewLength`

The new length of the string in characters, not counting a terminating **null** character.

If the string is **NULL**-terminated, the –1 default value sets the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string size to the current length of the string.

## Return value

This method does not return a value.

## Remarks

If you know that the string in the buffer is **NULL**-terminated, you can omit the *nNewLength* parameter. If your string is not **NULL**-terminated, then use *nNewLength* to specify its length. The address returned by [GetBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getbuffer) is not valid after the call to **ReleaseBuffer** or any other [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) operation.

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::GetBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getbuffer)