## Description

Creates an [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) from the specified [HSTRING_BUFFER](https://learn.microsoft.com/windows/desktop/WinRT/hstring-buffer).

## Parameters

### `bufferHandle`

Type: [in] **[HSTRING_BUFFER](https://learn.microsoft.com/windows/desktop/WinRT/hstring-buffer)**

The buffer to use for the new [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). You must use the [WindowsPreallocateStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspreallocatestringbuffer) function to create the [HSTRING_BUFFER](https://learn.microsoft.com/windows/desktop/WinRT/hstring-buffer).

### `string`

Type: [out] **[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)***

The newly created [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) that contains the contents of *bufferHandle*.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) was created successfully. |
| **E_POINTER** | *string* is **NULL**. |
| **E_INVALIDARG** | *bufferHandle* was not created by calling the [WindowsPreallocateStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspreallocatestringbuffer) function, or the caller has overwritten the terminating NULL character in *bufferHandle*. |

## Remarks

Use the **WindowsPromoteStringBuffer** function to create a new [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) from an [HSTRING_BUFFER](https://learn.microsoft.com/windows/desktop/WinRT/hstring-buffer). Calling the **WindowsPromoteStringBuffer** function converts the mutable buffer to an immutable **HSTRING**. Use the [WindowsPreallocateStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspreallocatestringbuffer) function to create the **HSTRING_BUFFER**.

If the **WindowsPromoteStringBuffer** call fails, you can call the [WindowsDeleteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestringbuffer) function to discard the mutable buffer.

Each call to the **WindowsPromoteStringBuffer** function must be matched with a corresponding call to [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring).

## Examples

The following code example demonstrates how to use the **WindowsPromoteStringBuffer** function.

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
        // Fill in the buffer

        hr = WindowsPromoteStringBuffer(hStringBuffer, &hString);

        if (SUCCEEDED(hr))
        {
            WindowsDeleteString(hString);
        }
        else
        {
            WindowsDeleteStringBuffer(hStringBuffer);
        }
    }
}
```

## See also

[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)

[HSTRING_BUFFER](https://learn.microsoft.com/windows/desktop/WinRT/hstring-buffer)

[WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring)

[WindowsDeleteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestringbuffer)

[WindowsPreallocateStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspreallocatestringbuffer)