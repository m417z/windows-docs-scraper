## Description

Replaces all occurrences of a set of characters in the specified string with another set of characters to create a new string.

## Parameters

### `string`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The original string.

### `stringReplaced`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The string to be replaced.

### `stringReplaceWith`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The string to replace all occurrences of *stringReplaced*.
If this parameter is **NULL**, all instances of *stringReplaced* are removed.

### `newString`

Type: [out] **[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)***

A string that is equivalent to the original, except that all instances of *stringReplaced* are replaced with *stringReplaceWith*.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The string replacement was successful. |
| **E_INVALIDARG** | *newString* is **NULL**, *stringReplaced* is empty, or the length of *string1* plus the length of *string2* is greater than **MAXUINT32**, which is 4,294,967,295; that is, hexadecimal 0xFFFFFFFF. |
| **E_OUTOFMEMORY** | Failed to allocate the new string. |

## Remarks

Each call to the **WindowsReplaceString** function must be matched with a corresponding call to [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring).

## See also

[WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)