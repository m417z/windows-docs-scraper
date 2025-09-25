## Description

Allocates a mutable character buffer for use in [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) creation.

## Parameters

### `length`

Type: [in] **UINT32**

The size of the buffer to allocate. A value of zero corresponds to the empty string.

### `charBuffer`

Type: [out] **WCHAR****

The mutable buffer that holds the characters. Note that the buffer already contains a terminating **NULL** character.

### `bufferHandle`

Type: [out] **[HSTRING_BUFFER](https://learn.microsoft.com/windows/desktop/WinRT/hstring-buffer)***

The preallocated string buffer, or **NULL** if *length* is 0.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) was created successfully. |
| **E_POINTER** | *mutableBuffer* or *bufferHandle* is **NULL**. |
| **MEM_E_INVALID_SIZE** | The requested [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) allocation size is too large. |
| **E_OUTOFMEMORY** | Failed to allocate the [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). |

## Remarks

Use the **WindowsPreallocateStringBuffer** function to create a mutable character buffer that you can manipulate prior to committing it to an immutable [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). When you have finished populating the *mutableBuffer* with your string, call the [WindowsPromoteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspromotestringbuffer) function with the *bufferHandle* parameter to create the **HSTRING**. You must write exactly *length* characters into the buffer.
**Windows 10 Version 1803, Windows Server Version 1803, and later**: You are permitted to write a null terminator after *length* characters.

Call the [WindowsDeleteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestringbuffer) function to discard the mutable buffer prior to promotion. If the buffer has already been promoted by a call to [WindowsPromoteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspromotestringbuffer), call the [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring) function to discard the string. If the **WindowsPromoteStringBuffer** call fails, you can call the **WindowsDeleteStringBuffer** function to discard the mutable buffer.

## Examples

The following code example demonstrates how to use the **WindowsPreallocateStringBuffer** function.

```cpp
#include <winstring.h>

int main()
{
    HSTRING hString = NULL;
    HSTRING_BUFFER hStringBuffer = NULL;
    PWSTR strBuffer = NULL;

    HRESULT hr = WindowsPreallocateStringBuffer(10, &strBuffer, &hStringBuffer);

    if (SUCCEEDED(hr))
    {
        CopyMemory(strBuffer, L"1234567890", 10 * sizeof(wchar_t));
        hr = WindowsPromoteStringBuffer(hStringBuffer, &hString);
    }

    WindowsDeleteString(hString);
}
```

## See also

[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)

[HSTRING_BUFFER](https://learn.microsoft.com/windows/desktop/WinRT/hstring-buffer)

[WindowsDeleteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestringbuffer)

[WindowsPromoteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspromotestringbuffer)