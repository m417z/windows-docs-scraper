## Description

Creates a new [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) based on the specified source string.

## Parameters

### `sourceString`

Type: [in, optional] **LPCWSTR**

The UTF-16LE-encoded text buffer to use as the source for the new [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). To create a new, empty, or **NULL** string, pass **NULL** for *sourceString* and 0 for *length*.

This buffer is not required to be null-terminated. **WindowsCreateString** will copy its contents and add a null-terminator in the new buffer backing the returned [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring).

### `length`

Type: [in] **UINT32**

The length of *sourceString*, in Unicode characters. Must be 0 if *sourceString* is **NULL**.

### `string`

Type: [out] **[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)***

A pointer to the newly created [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring), or **NULL** if an error occurs. Any existing content in *string* is overwritten. The **HSTRING** is a standard handle type.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) was created successfully. |
| **E_INVALIDARG** | *string* is **NULL**. |
| **E_OUTOFMEMORY** | Failed to allocate the new [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). |
| **E_POINTER** | *sourceString* is **NULL** and *length* is non-zero. |

## Remarks

Use the **WindowsCreateString** function to allocate a new [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). The Windows Runtime copies *string* to the backing buffer of the new **HSTRING** and manages the buffer lifetime by using a reference count. Call the [WindowsCreateStringReference](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestringreference) function to create a *fast-pass string*, which uses an existing string without copying it.

Call the [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring) function to de-allocate the [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). Each call to the **WindowsCreateString** function must be matched by a call to **WindowsDeleteString**.

To create a new, empty, or **NULL** string, pass **NULL** for *sourceString* and 0 for *length*.

If *sourceString* has embedded null characters, the **WindowsCreateString** function copies all characters to the terminating null character.

## See also

[WindowsCreateStringReference](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestringreference)

[WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)