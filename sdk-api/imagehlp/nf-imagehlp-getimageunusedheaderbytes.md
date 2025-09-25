# GetImageUnusedHeaderBytes function

## Description

Retrieves the offset and size of the part of the PE header that is currently unused.

## Parameters

### `LoadedImage` [in]

A pointer to a
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image) structure that is returned from a call to
[MapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-mapandload) or [ImageLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageload).

### `SizeUnusedHeaderBytes` [out]

A pointer to a variable to receive the size, in bytes, of the part of the image's header which is unused.

## Return value

If the function succeeds, the return value is the offset from the base address of the first unused header byte.

If the function fails, the return value is zero. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image)