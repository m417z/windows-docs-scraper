# DrvDescribePixelFormat function

## Description

The **DrvDescribePixelFormat** function describes the pixel format for a device-specified [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) by writing a pixel format description to a PIXELFORMATDESCRIPTOR structure.

## Parameters

### `dhpdev`

Identifies the device for which pixel format information is requested.

### `iPixelFormat`

Specifies the index number of the requested pixel format.

### `cjpfd`

Specifies the maximum number of bytes that can be written to the structure pointed to by *ppfd*.

### `ppfd`

Pointer to a PIXELFORMATDESCRIPTOR structure (described in the Microsoft Windows SDK documentation) that is to receive information about the pixel format. This parameter can be **NULL**.

## Return value

The return value is the maximum pixel format index if the function is successful. Otherwise, it is zero, and an error code is logged.

## Remarks

A display driver that supports 3D graphics hardware can support windows with different pixel formats on a single display surface. The pixel format must correspond to a configuration supported by the graphics hardware.

**DrvDescribePixelFormat** fills in the structure pointed to by *ppfd* if this parameter is not **NULL**.

The returned maximum pixel format index can be used by applications that need to obtain a device context's maximum pixel format index. The pixel formats that a device supports are identified by positive one-based integer indices.

The pixel format functions are used in conjunction with the window object services functions to track and update pixel formats of windows on a display surface.