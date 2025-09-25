# DrvSwapBuffers function

## Description

The **DrvSwapBuffers** function displays the contents of the window's associated hidden buffer on the specified surface.

## Parameters

### `pso`

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the target surface to be modified for display.

### `pwo`

Pointer to the [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) structure that defines the region on the target surface with which the back buffer will be swapped.

## Return value

The return value is **TRUE** if the function is successful; it is **FALSE** upon failure.

## Remarks

**DrvSwapBuffers** can affect the display only if the pixel format for the window specified by *pwo* is double-buffered. The content of the hidden buffer is undefined after the swap occurs.

This function is required if the driver supports a pixel format with double buffering; that is, if PFD_DOUBLEBUFFER is set in the **dwFlags** member of the PIXELFORMATDESCRIPTOR structure.

## See also

[DrvDescribePixelFormat](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdescribepixelformat)