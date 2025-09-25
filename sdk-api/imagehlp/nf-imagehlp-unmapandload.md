# UnMapAndLoad function

## Description

Deallocate all resources that are allocated by a previous call to the
[MapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-mapandload) function.

## Parameters

### `LoadedImage` [in]

A pointer to a
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image) structure. This structure is obtained through a call to the
[MapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-mapandload) function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**UnMapAndLoad** function must be used to deallocate all resources that are allocated by a previous call to
[MapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-mapandload). This function also writes a new checksum value into the image before the file is closed. This ensures that if a file is changed, it can be successfully loaded by the system loader.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image)

[MapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-mapandload)