## Description

Discards a preallocated string buffer if it was not promoted to an [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring).

## Parameters

### `bufferHandle`

Type: [in] **[HSTRING_BUFFER](https://learn.microsoft.com/windows/desktop/WinRT/hstring-buffer)**

The buffer to discard. The **WindowsDeleteStringBuffer** function raises an exception if *bufferHandle* was not allocated by a call to the [WindowsPreallocateStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspreallocatestringbuffer) function.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The buffer was discarded successfully. |
| **E_POINTER** | *bufferHandle* is **NULL**. |

## Remarks

Use the **WindowsDeleteStringBuffer** function to discard a string buffer that was created by the [WindowsPreallocateStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspreallocatestringbuffer) function but has not been promoted to an [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) by the [WindowsPromoteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspromotestringbuffer) function.

**Note** Calling [WindowsPromoteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspromotestringbuffer) after calling **WindowsDeleteStringBuffer** with the same buffer handle is undefined.

## Examples

The following code example demonstrates how to use the **WindowsDeleteStringBuffer** function.

```cpp
int main()
{
    HSTRING_BUFFER hStringBuffer = NULL;
    PWSTR strBuffer = NULL;
    HRESULT hr = WindowsPreallocateStringBuffer(10, &strBuffer, &hStringBuffer);

    // You hit a case in which you need to discard the buffer.

    WindowsStringDeleteBuffer(hStringBuffer);
}
```

## See also

[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)

[HSTRING_BUFFER](https://learn.microsoft.com/windows/desktop/WinRT/hstring-buffer)

[WindowsPreallocateStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspreallocatestringbuffer)

[WindowsPromoteStringBuffer](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowspromotestringbuffer)