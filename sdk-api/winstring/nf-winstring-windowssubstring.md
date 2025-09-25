## Description

Retrieves a substring from the specified string. The substring starts at the specified character position.

## Parameters

### `string`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The original string.

### `startIndex`

Type: [in] **UINT32**

The zero-based starting character position of a substring in this instance.

### `newString`

Type: [out] **[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)***

A string that is equivalent to the substring that begins at *startIndex* in *string*, or **NULL** if *startIndex* is equal to the length of *string*.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The substring was created successfully. |
| **E_INVALIDARG** | *newString* is **NULL**. |
| **E_BOUNDS** | *startIndex* is greater than the length of *string*. |
| **E_OUTOFMEMORY** | Failed to allocate the new substring. |

## Remarks

Each call to the **WindowsSubstring** function must be matched with a corresponding call to [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring).

## See also

[WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)