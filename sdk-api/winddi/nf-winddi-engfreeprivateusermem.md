# EngFreePrivateUserMem macro

## Description

The **EngFreePrivateUserMem** function deallocates a block of private user memory.

## Parameters

### `psl` [in]

Pointer to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure representing the DirectDraw surface with which the memory is associated.

### `p` [in]

Pointer to the block of user memory being deallocated.

## Remarks

This routine deallocates a block of memory allocated by [EngAllocPrivateUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocprivateusermem).

## See also

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local)

[EngAllocPrivateUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocprivateusermem)

[EngAllocUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocusermem)

[EngFreeUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreeusermem)