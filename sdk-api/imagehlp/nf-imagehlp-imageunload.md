# ImageUnload function

## Description

Deallocates resources from a previous call to the
[ImageLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageload) function.

## Parameters

### `LoadedImage` [in]

A pointer to a
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image) structure that is returned from a call to the
[ImageLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageload) function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

[ImageLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageload) and
**ImageUnload** share internal data that can be corrupted if multiple consecutive calls to
**ImageLoad** are performed. Therefore, make sure that you have called
**ImageLoad** only once before calling
**ImageUnload**.

## Remarks

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[ImageLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageload)

[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image)