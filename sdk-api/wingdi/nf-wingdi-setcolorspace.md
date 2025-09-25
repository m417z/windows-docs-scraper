# SetColorSpace function

## Description

The **SetColorSpace** function defines the input [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space) for a given device context.

## Parameters

### `hdc`

Specifies the handle to a device context.

### `hcs`

Identifies handle to the color space to set.

## Return value

If this function succeeds, the return value is a handle to the *hColorSpace* being replaced.

If this function fails, the return value is **NULL**.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)