## Description

Decrements the reference count of a string buffer.

## Parameters

### `string`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The string to be deleted. If *string* is a fast-pass string created by [WindowsCreateStringReference](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestringreference), or if *string* is **NULL** or empty, no action is taken and **S_OK** is returned.

## Return value

Type: **HRESULT**

This function always returns **S_OK**.

## Remarks

Use the **WindowsDeleteString** function to de-allocate an [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). Calling **WindowsDeleteString** decrements the reference count of the backing buffer, and if the reference count reaches 0, the Windows Runtime de-allocates the buffer.

## See also

[WindowsCreateString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestring)

[WindowsCreateStringReference](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestringreference)