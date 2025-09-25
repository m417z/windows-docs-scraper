# MapAndLoad function

## Description

Maps an image and preloads data from the mapped file.

## Parameters

### `ImageName` [in]

The file name of the image (executable file or DLL) that is loaded.

### `DllPath` [in]

The path used to locate the image if the name provided cannot be found. If this parameter is **NULL**, then the search path rules set using the
[SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw) function apply.

### `LoadedImage` [out]

A pointer to a
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image) structure that receives information about the image after it is loaded.

### `DotDll` [in]

The default extension to be used if the image name does not contain a file name extension. If the value is **TRUE**, a .DLL extension is used. If the value is **FALSE**, then an .EXE extension is used.

### `ReadOnly` [in]

The access mode. If this value is **TRUE**, the file is mapped for read-access only. If the value is **FALSE**, the file is mapped for read and write access.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**MapAndLoad** function maps an image and preloads data from the mapped file. The corresponding function,
[UnMapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-unmapandload), must be used to deallocate all resources that are allocated by the
**MapAndLoad** function.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image)

[UnMapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-unmapandload)