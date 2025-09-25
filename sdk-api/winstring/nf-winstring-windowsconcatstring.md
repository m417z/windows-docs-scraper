## Description

Concatenates two specified strings.

## Parameters

### `string1`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The first string to be concatenated.

### `string2`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The second string to be concatenated.

### `newString`

Type: [out] **[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)***

The concatenation of *string1* and *string2*. If *string1* and *string2* are **NULL**, *newString* is **NULL**. If either *string1* or *string2* is **NULL**, *newString* is a copy of the non-null string.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The concatenated string was created successfully. |
| **E_INVALIDARG** | *newString* is **NULL**, or the length of *string1* plus the length of *string2* is greater than **MAXUINT32**, which is 4,294,967,295; that is, hexadecimal 0xFFFFFFFF. |
| **E_OUTOFMEMORY** | Failed to allocate the concatenated string. |

## Remarks

Each call to the **WindowsConcatString** function must be matched with a corresponding call to [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring).

## See also

[WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)