# RtlInt64ToUnicodeString function

## Description

The **RtlInt64ToUnicodeString** routine converts a specified unsigned 64-bit integer value to a Unicode string that represents the value in a specified base.

## Parameters

### `Value` [in]

Specifies the ULONGLONG value to convert.

### `Base` [in, optional]

Specifies the base to use when converting *Value* to a string. The possible values are:

| Value | Base |
| --- | --- |
| 16 | Hexadecimal |
| 8 | Octal |
| 2 | Binary |
| 0 or 10 | Decimal |

### `String` [in, out]

Pointer to the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that receives the string representation of *Value*. The buffer specified by the *Buffer* of *String* must be large enough to hold the result.

## Return value

**RtlInt64ToUnicodeString** returns an NTSTATUS value. Possible return values include :

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The routine successfully converted *Value* to a Unicode string. |
| **STATUS_BUFFER_OVERFLOW** | *Value* is too large to convert, or the **UNICODE_STRING** structure is too small to hold the result. |
| **STATUS_INVALID_PARAMETER** | The specified code base is not valid. The only valid values are 0, 2, 8, 10, and 16. |

## See also

[RtlAppendUnicodeStringToString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlappendunicodestringtostring)

[RtlUnicodeStringToInteger](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtointeger)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)