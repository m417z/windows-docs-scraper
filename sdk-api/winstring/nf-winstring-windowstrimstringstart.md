## Description

Removes all leading occurrences of a specified set of characters from the source string.

## Parameters

### `string`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The string to be trimmed.

### `trimString`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The characters to remove from *string*.

### `newString`

Type: [out] **[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)***

The string that remains after all occurrences of characters in the *trimString* parameter are removed from the start of *string*, or **NULL** if *trimString* contains all of the characters in *string*.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The trimmed string was created successfully. |
| **E_INVALIDARG** | *newString* is **NULL**, or *trimString* is empty. |
| **E_OUTOFMEMORY** | Failed to allocate the trimmed string. |

## Remarks

Each call to the **WindowsTrimStringStart** function must be matched with a corresponding call to [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)

## See also

[WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)