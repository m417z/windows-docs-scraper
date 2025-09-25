## Description

Provides a way to for debuggers to display the value of a Windows Runtime [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) in another address space, remotely, or from a dump.

## Parameters

### `targetHString`

[in]

The [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) to inspect.

### `machine`

The format of the target address space. Valid values are **IMAGE_FILE_MACHINE_AMD64** for Win64, **IMAGE_FILE_MACHINE_I386** for Win32, or **IMAGE_FILE_MACHINE_ARM** for 32-bit ARM.

### `callback`

[in]

A callback function to read the string buffer from the target address space. This function is called before the *length* and *targetStringAddress* parameters are computed by the **WindowsInspectString2** function.

### `context`

[in, optional]

Custom context data passed to the callback.

### `length`

[out]

The length of the string in the target address space, if the call to *callback* is successful; otherwise, 0.

### `targetStringAddress`

[out]

The target address of the raw **PCWSTR**, if the call to *callback* is successful; otherwise, **NULL**.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | * The *machine* value is not **IMAGE_FILE_MACHINE_AMD64**, **IMAGE_FILE_MACHINE_I386**, or **IMAGE_FILE_MACHINE_ARM** or<br>* *targetHString* is not a correctly formed [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). |

## Remarks

The [WindowsInspectString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsinspectstring) function passes the input and output pointers as native pointer-sized values. If the current platform is Win32, that function returns an error for processes that are Win64.

**WindowsInspectString2** enables cross-architecture debugging by allowing up to 64-bit values when called from both Win32 and Win64 applications.

## See also

[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)

[PINSPECT_HSTRING_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winstring/nc-winstring-pinspect_hstring_callback)

[WindowsCreateString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestring)

[WindowsInspectString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsinspectstring)