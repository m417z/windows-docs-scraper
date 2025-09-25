# GetTimestampForLoadedLibrary function

## Description

Retrieves the time stamp of a loaded image.

## Parameters

### `Module` [in]

The base address of an image that is mapped into memory by a call to the
[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) function.

## Return value

If the function succeeds, the return value is the time stamp from the image.

If the function fails, the return value is zero. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The time stamp for an image is initially set by the linker, but it can be modified by operations such as rebasing. The value is represented in the number of seconds elapsed since midnight (00:00:00), January 1, 1970, Universal Coordinated Time, according to the system clock. The time stamp can be printed using the C run-time (CRT) function ctime.

All [DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions), such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)

[ReBaseImage](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-rebaseimage)

[ReBaseImage64](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-rebaseimage64)