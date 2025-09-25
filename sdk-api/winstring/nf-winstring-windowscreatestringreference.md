## Description

Creates a new string reference based on the specified string.

## Parameters

### `sourceString`

Type: [in] **PCWSTR**

A null-terminated string to use as the source for the new [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring).

A value of **NULL** represents the empty string, if the value of *length* is 0. Should be allocated on the stack frame.

### `length`

Type: [in] **UINT32**

The length of *sourceString*, in Unicode characters. Must be 0 if *sourceString* is **NULL**. If greater than 0, *sourceString* must have a terminating null character.

### `hstringHeader`

Type: [out] **[HSTRING_HEADER](https://learn.microsoft.com/windows/desktop/api/hstring/ns-hstring-hstring_header)***

A pointer to a structure that the Windows Runtime uses to identify *string* as a string reference, or fast-pass string.

### `string`

Type: [out] **[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)***

A pointer to the newly created string, or **NULL** if an error occurs. Any existing content in *string* is overwritten. The [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) is a standard handle type.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) was created successfully. |
| **E_INVALIDARG** | Either *string* or *hstringHeader* is **NULL**, or *string* is not null-terminated. |
| **E_OUTOFMEMORY** | Failed to allocate the new [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). |
| **E_POINTER** | *sourceString* is **NULL** and *length* is non-zero. |

## Remarks

Use the **WindowsCreateStringReference** function to create an [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) from an existing string. This kind of **HSTRING** is named a *fast-pass string*. Unlike an **HSTRING** created by the [WindowsCreateString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestring) function, the lifetime of the backing buffer in the new **HSTRING** is not managed by the Windows Runtime. The caller allocates *sourceString* on the stack frame, together with an uninitialized [HSTRING_HEADER](https://learn.microsoft.com/windows/desktop/api/hstring/ns-hstring-hstring_header), to avoid a heap allocation and eliminate the risk of a memory leak. The caller must ensure that *sourceString* and the contents of *hstringHeader* remain unchanged during the lifetime of the attached **HSTRING**.

You don't need to call the [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring) function to de-allocate a fast-pass [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) created by the **WindowsCreateStringReference** function.

To create an empty [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring), pass **NULL** for *sourceString* and 0 for *length*.

The Windows Runtime tracks a fast-pass string by using an [HSTRING_HEADER](https://learn.microsoft.com/windows/desktop/api/hstring/ns-hstring-hstring_header) structure, which is returned in the *hstringHeader* out parameter. Do not change the contents of the **HSTRING_HEADER**.

## See also

[WindowsCreateString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestring)

[WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)