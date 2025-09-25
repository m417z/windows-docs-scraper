# EngMapModule function

## Description

The **EngMapModule** function returns the address and size of a file that was loaded by [EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule), [EngLoadModuleForWrite](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmoduleforwrite), [EngLoadImage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadimage), or [EngMapFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfile).

## Parameters

### `h` [in]

Handle to the file to be memory-mapped.

### `pSize` [in]

Pointer to a memory location that receives the size, in bytes, of the memory-mapped file.

## Return value

**EngMapModule** returns a pointer to the view of the file identified by *h*.

## Remarks

A driver can open and read a file using [EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule) and **EngMapModule**.

## See also

[EngFreeModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreemodule)

[EngLoadImage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadimage)

[EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule)

[EngLoadModuleForWrite](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmoduleforwrite)

[EngMapFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfile)