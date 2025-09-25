## Description

Retrieves a substring from the specified string. The substring starts at a specified character position and has a specified length.

## Parameters

### `string`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The original string.

### `startIndex`

Type: [in] **UINT32**

The zero-based starting character position of a substring in this instance.

### `length`

Type: [in] **UINT32**

The number of characters in the substring.

### `newString`

Type: [out] **[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)***

A string that is equivalent to the substring that begins at *startIndex* in *string*, or **NULL** if *startIndex* is equal to the length of *string*.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The substring was created successfully. |
| **E_INVALIDARG** | *newString* is **NULL**, or *startIndex* plus *length* is greater than **MAXUINT32**, which is 4,294,967,295; that is, hexadecimal 0xFFFFFFFF. |
| **E_BOUNDS** | *startIndex* is greater than the length of *string*, or *startIndex* plus *length* indicates a position not within *string*. |
| **E_OUTOFMEMORY** | Failed to allocate the new substring. |

## Remarks

Each call to the **WindowsSubstringWithSpecifiedLength** function must be matched with a corresponding call to [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring).

## See also

[WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)