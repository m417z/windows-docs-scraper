# EngFreeModule function

## Description

The **EngFreeModule** function unmaps a file from system memory.

## Parameters

### `h` [in]

Handle to the memory-mapped file to be freed. This handle was obtained from [EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule) or [EngLoadModuleForWrite](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmoduleforwrite).

## Return value

None

## See also

[EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule)

[EngLoadModuleForWrite](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmoduleforwrite)

[EngMapModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapmodule)