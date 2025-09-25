# CHString::GetBuffer

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetBuffer** method returns a pointer to the internal character buffer for the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) object.

## Parameters

### `nMinBufLength`

The minimum size of the character buffer in characters. This value does not include space for a **NULL** terminator.

## Return value

An **LPWSTR** pointer to the object's (**NULL**-terminated) character buffer.

## Remarks

The returned **LPWSTR** is not **const** and therefore allows direct modification of [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) contents.

If you use the pointer returned by **GetBuffer** to change the string contents, you must call [ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-releasebuffer) before using any other [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) methods.

After a call to [ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-releasebuffer), the address returned by **GetBuffer** may not be valid because additional [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) operations can cause the **CHString** buffer to be reallocated. If you do not change the length of the **CHString** string, the buffer is not reallocated. The buffer memory is freed automatically when the **CHString** object is destroyed.

Note that if you keep track of the string length yourself, you should not append the terminating **NULL** character. You must, however, specify the final string length when you release the buffer with [ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-releasebuffer). If you do append a terminating **NULL** character, you should pass –1 for the length to **ReleaseBuffer**, which calls **wcslen** on the buffer to determine its length.

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::GetBufferSetLength](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getbuffersetlength)

[CHString::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-releasebuffer)