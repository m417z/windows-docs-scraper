# GetSystemWow64Directory2W function

## Description

Retrieves the path of the system directory used by [WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications), using the specified image file machine type. This directory is not present on 32-bit Windows.

## Parameters

### `lpBuffer` [out]

A pointer to the buffer to receive the path. This path does not end with a backslash.

### `uSize` [in]

The maximum size of the buffer, in **TCHARs**.

### `ImageFileMachineType` [in]

An [IMAGE_FILE_MACHINE_*](https://learn.microsoft.com/windows/desktop/SysInfo/image-file-machine-constants) value that specifies the machine to test.

## Return value

If the function succeeds, the return value is the length, in **TCHARs**, of the string copied to the buffer, not including the terminating null character. If the length is greater than the size of the buffer, the return value is the size of the buffer required to hold the path.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

On systems that support multiple [WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications) architectures, you can use **GetSystemWow64Directory2** to retrieve appropriate system directory associated with the WOW64 architecture specified by *ImageFileMachineType*.

WOW64 uses the system directory to store shared 32-bit code on 64-bit Windows. Most applications have no need to access this directory explicitly.

For more information on WOW64, see
[Running 32-bit Applications](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications).

> [!NOTE]
> The wow64apiset.h header defines GetSystemWow64Directory2 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetSystemWow64Directory](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-getsystemwow64directorya)