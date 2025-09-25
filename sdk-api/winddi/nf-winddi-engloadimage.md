# EngLoadImage macro

## Description

The **EngLoadImage** function loads the specified executable image into kernel-mode memory.

## Parameters

### `filename` [in]

Pointer to a null-terminated string that names the file containing the executable image to be loaded.

## Remarks

A driver can use **EngLoadImage** to map an executable image into kernel-mode memory. For example, a printer driver can call **EngLoadImage** to load a minidriver.

**EngLoadImage** requires that the image file to be loaded have a *.dll* suffix. The driver must include this suffix in the *pwszDriver* string.

To execute a section of code within the loaded image, the driver should obtain the function address from [EngFindImageProcAddress](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfindimageprocaddress).

The file identified by *pwszDriver* must be located in the *%SystemRoot%\System32* directory or within a directory found in the directory hierarchy under *%SystemRoot%\System32*.

Drivers that need to load a module as data only should call [EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule) or [EngLoadModuleForWrite](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmoduleforwrite) instead of this function.

## See also

[EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule)

[EngLoadModuleForWrite](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmoduleforwrite)

[EngUnloadImage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunloadimage)