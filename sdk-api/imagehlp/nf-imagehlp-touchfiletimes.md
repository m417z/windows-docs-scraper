# TouchFileTimes function

## Description

Updates the date and time at which the specified file was last modified.

## Parameters

### `FileHandle` [in]

A handle to the file of interest.

### `pSystemTime` [in]

A pointer to a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. If this parameter is **NULL**, the current system date and time is used.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[Image Help Library Overview](https://learn.microsoft.com/windows/desktop/Debug/image-help-library)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)