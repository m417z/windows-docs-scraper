# EngLoadModule function

## Description

The **EngLoadModule** function loads the specified data module into system memory for reading.

## Parameters

### `pwsz` [in]

Pointer to a null-terminated string that contains the name of the data file to be loaded.

## Return value

If **EngLoadModule** succeeds, the return value is a handle to the module that was loaded. Otherwise, the return value is **NULL**.

## Remarks

**EngLoadModule** loads a data file into system memory with read-only permission. To access the loaded module, the driver should call [EngMapModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapmodule) with the handle returned by this function.

The file identified by *pwsz* must be located in the *%SystemRoot%\System32* directory or within a directory found in the directory hierarchy under *%SystemRoot%\System32*.

To load a writable module, the driver should call [EngLoadModuleForWrite](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmoduleforwrite). Drivers that need to load an image as executable code should call [EngLoadImage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadimage) instead of this function.

## See also

[EngFreeModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreemodule)

[EngLoadModuleForWrite](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmoduleforwrite)

[EngMapModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapmodule)