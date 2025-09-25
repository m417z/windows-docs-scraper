# EngLoadModuleForWrite function

## Description

The **EngLoadModuleForWrite** function loads the specified executable module into system memory for writing.

## Parameters

### `pwsz` [in]

Pointer to a null-terminated string that contains the name of the file to be loaded.

### `cjSizeOfModule` [in]

Specifies the size, in bytes, of the module to be loaded.

## Return value

If **EngLoadModuleForWrite** succeeds, the return value is a handle to the module that was loaded. Otherwise, **NULL** is returned.

## Remarks

**EngLoadModuleForWrite** loads a data file into system memory with write permission. To access the loaded module, the driver should call [EngMapModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapmodule) with the handle returned by this function.

**EndLoadModuleForWrite** loads the file into memory that is the same size as the file when *cjSizeOfModule* is zero. If *cjSizeOfModule* is greater than zero, GDI extends or truncates the file to be exactly *cjSizeOfModule* bytes in size before loading it. No assumptions should be made about the contents of memory that extend beyond the file when *cjSizeOfModule* is greater than the file's original size.

The file identified by *pwsz* must be located in the *%SystemRoot%\System32* directory or within a directory found in the directory hierarchy under *%SystemRoot%\System32*.

To load a module with read-only permissions, the driver should call [EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule). Drivers that need to load an image as executable code should call [EngLoadImage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadimage) instead of this function.

## See also

[EngFreeModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreemodule)

[EngLoadImage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadimage)

[EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule)

[EngMapModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapmodule)