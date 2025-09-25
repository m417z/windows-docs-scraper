# DrvSetPixelFormat function

## Description

The **DrvSetPixelFormat** function sets the pixel format of a window.

## Parameters

### `pso`

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure with which the window is associated.

### `iPixelFormat`

Index that specifies the device format to which the pixel format is to be set. The pixel formats that a device supports are identified by positive one-based integer indices starting at 1.

### `hwnd`

Handle to the window whose pixel format is to be set.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

Setting the pixel format more than once can result in complications for Window Manager and for multithreaded applications. Consequently, the pixel format of a window can be set only once and must remain unchanged.

## See also

[DrvDescribePixelFormat](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdescribepixelformat)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)