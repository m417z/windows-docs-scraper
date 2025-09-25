# CHString::GetBufferSetLength

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetBufferSetLength** method returns a pointer to the internal character buffer for the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) object, truncating or increasing its length if necessary to exactly match the length specified in *nNewLength*.

## Parameters

### `nNewLength`

Exact size of the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) character buffer, measured in characters.

## Return value

Returns an **LPWSTR** pointer to the object's (NULL-terminated) character buffer.

## Remarks

The returned **LPWSTR** pointer, which is not **const**, allows direct modification of [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) contents.

If you use the pointer returned by [GetBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getbuffer) to change the string contents, you must call [ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-releasebuffer) before using any other [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) methods.

After a call to [ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-releasebuffer), the address returned by **GetBufferSetLength** may not be valid because additional [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) operations can cause the **CHString** buffer to be reallocated. If you do not change the length of the **CHString** string, the buffer is not reassigned. The buffer memory is freed automatically when the **CHString** object is destroyed.

Note that if you keep track of the string length yourself, you should not append the terminating **NULL** character. You must, however, specify the final string length when you release the buffer with [ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-releasebuffer). If you do append a terminating **NULL** character when you call **ReleaseBuffer**, you should pass –1 (the default) for the length. The **ReleaseBuffer** method calls the wcslen function on the buffer to determine its length.

#### Examples

The following code example shows the use of **CHString::GetBufferSetLength**.

```cpp
CHString str;
LPWSTR pstr = str.GetBufferSetLength(3);
pstr[0] = 'I';
pstr[1] = 'c';
pstr[2] = 'e';

// No need for trailing zero or call to ReleaseBuffer()
// because GetBufferSetLength() set it for you.

str += " hockey is best!";
printf( "str: %S\n", (LPCWSTR)str );
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::GetBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getbuffer)

[CHString::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-releasebuffer)