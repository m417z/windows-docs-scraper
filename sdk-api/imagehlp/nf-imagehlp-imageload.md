# ImageLoad function

## Description

Maintains a list of loaded DLLs.

## Parameters

### `DllName` [in]

The name of the image.

### `DllPath` [in]

The path used to locate the image if the name provided cannot be found. If **NULL** is used, then the search path rules set forth in the
[SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw) function apply.

## Return value

If the function succeeds, the return value is a pointer to a
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image) structure.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**ImageLoad** function is used to maintain a list of loaded DLLs. If the image has already been loaded, the prior
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image) is returned. Otherwise, the new image is added to the list.

The
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image) structure must be deallocated by the
[ImageUnload](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageunload) function.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[ImageUnload](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageunload)

[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image)