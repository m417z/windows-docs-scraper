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

A callback function to read the string buffer from the target address space. This function is called before the *length* and *targetStringAddress* parameters are computed by the **WindowsInspectString** function.

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
| **E_INVALIDARG** | * **IMAGE_FILE_MACHINE_AMD64** was specified for *machine*, but the current platform is not Win64, or<br>* *machine* is not **IMAGE_FILE_MACHINE_AMD64**, **IMAGE_FILE_MACHINE_I386**, or **IMAGE_FILE_MACHINE_ARM**, or<br>* *targetHString* is not a correctly formed [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring). |

## See also

[**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring)

[PINSPECT_HSTRING_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winstring/nc-winstring-pinspect_hstring_callback)

[WindowsCreateString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowscreatestring)