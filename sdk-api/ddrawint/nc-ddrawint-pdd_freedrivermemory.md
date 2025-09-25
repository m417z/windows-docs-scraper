## Description

The **DdFreeDriverMemory** callback function frees offscreen or nonlocal display memory to satisfy a new allocation request.

## Parameters

### `unnamedParam1`

Points to a [DD_FREEDRIVERMEMORYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_freedrivermemorydata) structure that contains the details of the free request.

## Return value

**DdFreeDriverMemory** returns one of the following callback codes:

## Remarks

The driver should implement **DdFreeDriverMemory** when it has DirectDraw manage all offscreen display memory management, including allocations for [DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap). DirectDraw requests for allocations in offscreen memory should always take precedence over GDI device bitmap allocations.

DirectDraw calls **DdFreeDriverMemory** when it does not have enough offscreen or nonlocal display memory to allocate a surface requested by an application. The driver should move a GDI device bitmap from offscreen memory into system memory and then immediately return. Bitmap moves can be accomplished by calling [EngModifySurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmodifysurface).

DirectDraw will continually call **DdFreeDriverMemory** until there is enough offscreen memory from which to allocate the requested surface or until the driver returns DDERR_OUTOFMEMORY.

## See also

[DD_FREEDRIVERMEMORYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_freedrivermemorydata)

[DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap)

[EngModifySurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmodifysurface)

[HeapVidMemAllocAligned](https://learn.microsoft.com/windows/desktop/api/dmemmgr/nf-dmemmgr-heapvidmemallocaligned)