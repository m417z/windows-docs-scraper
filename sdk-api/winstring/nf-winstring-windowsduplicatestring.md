## Description

Creates a copy of the specified string.

## Parameters

### `string`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The string to be copied.

### `newString`

Type: [out] **[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)***

A copy of *string*.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) was copied successfully. |
| **E_INVALIDARG** | *newString* is **NULL**. |
| **E_OUTOFMEMORY** | Failed to allocate the new [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). |

## Remarks

Use the **WindowsDuplicateString** function to copy an [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). If *string* was created by calling the [WindowsCreateString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestring) function, the reference count of the backing buffer is incremented. If *string* was created by calling the [WindowsCreateStringReference](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestringreference) function, the Windows Runtime copies its source string to a new buffer and starts a reference count, which means that *newString* is not a fast-pass string.

Each call to the **WindowsDuplicateString** function must be matched with a corresponding call to [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring).

## See also

[WindowsCreateString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestring)

[WindowsCreateStringReference](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestringreference)

[WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)