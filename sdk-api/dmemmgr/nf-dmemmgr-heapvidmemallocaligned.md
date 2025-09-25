# HeapVidMemAllocAligned function

## Description

The **HeapVidMemAllocAligned** function allocates [off_screen_memory](https://learn.microsoft.com/windows-hardware/drivers/) for a display driver by using the DirectDraw video memory heap manager.

## Parameters

### `lpVidMem` [in]

Pointer to a [VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory) structure that represents the DirectDraw heap from which to allocate the surface.

### `dwWidth` [in]

Is the width in bytes of the requested surface.

### `dwHeight` [in]

Is the height in scan lines of the requested surface.

### `lpAlignment` [in]

Pointer to a [SURFACEALIGNMENT](https://learn.microsoft.com/windows/desktop/api/dmemmgr/ns-dmemmgr-surfacealignment) structure that describes the alignment restrictions for the surface.

### `lpNewPitch` [out]

Is the location in which the resulting pitch value is written. This information is relevant only to linear (nonrectangular) off-screen heaps.

## Return value

**HeapVidMemAllocAligned** returns the FLATPTR offset of the resulting allocation upon success. Otherwise, it returns zero.

## Remarks

The driver should use the array of VIDEOMEMORY structures its [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo) function receives to determine the value of *lpVidMem* with which to call **HeapVidMemAllocAligned**. The driver receives this array in the *pvmList* parameter during the second call to **DrvGetDirectDrawInfo**. It is possible that **DrvGetDirectDrawInfo** might not be called when low memory conditions exist on the system. Consequently, the driver should always check to ensure that it has a non-NULL pointer in *pvmList*.

## See also

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo)

[SURFACEALIGNMENT](https://learn.microsoft.com/windows/desktop/api/dmemmgr/ns-dmemmgr-surfacealignment)

[VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory)

[VidMemFree](https://learn.microsoft.com/windows/desktop/api/dmemmgr/nf-dmemmgr-vidmemfree)