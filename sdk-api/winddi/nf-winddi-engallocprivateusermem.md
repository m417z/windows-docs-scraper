# EngAllocPrivateUserMem macro

## Description

The **EngAllocPrivateUserMem** function allocates a block of user memory from the address space of a specified process and inserts a caller-supplied tag before the allocation.

## Parameters

### `psl` [in]

Pointer to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure representing the Microsoft DirectDraw surface with which to associate the allocated memory.

### `cj` [in]

Specifies the number of bytes of memory to allocate.

### `tag` [in]

Specifies a 4-byte [pool tag](https://learn.microsoft.com/windows-hardware/drivers/) that uniquely identifies the driver that does the memory allocation. For more information about pool tags, see [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-exallocatepoolwithtag).

## Remarks

A DirectDraw driver might require a user-memory "scratch pad" in place of true video memory. Although this practice is discouraged due to its performance implications, it is occasionally necessary. This scratch memory is usually allocated only for a short period of time. After the memory has been allocated, it is used for the intended graphics operations, and then deallocated.

A problem arises if the driver instance is destroyed before the surface is unlocked. A particular case occurs when the system switches to a protected desktop as a result of a user pressing CTRL+ALT+DEL. In this situation, the mode switch is performed on a system process context. If the driver has any outstanding surface locks, such as when the mode switch happens before the surface has been unlocked, the driver will be required to destroy that surface on a different process context. The driver cannot call [EngFreeUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreeusermem) to deallocate the scratch memory since this entry point will fail if called on a different context from that used when the memory was allocated.

**EngAllocPrivateUserMem**, and [EngFreePrivateUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreeprivateusermem) are provided to address this problem. These two functions are identical to [EngAllocUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocusermem) and [EngFreeUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreeusermem), except that they do the extra work required to free memory allocated on a different process context. Process context information is stored with the DirectDraw object that owns the DirectDraw surface object to which *psl* points.

## See also

[DD_SURFACE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_global)

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local)

[EngAllocUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocusermem)

[EngFreePrivateUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreeprivateusermem)

[EngFreeUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreeusermem)