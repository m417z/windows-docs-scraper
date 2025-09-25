# GetColorSpace function

## Description

The **GetColorSpace** function retrieves the handle to the input [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space) from a specified device context.

## Parameters

### `hdc`

Specifies a device context that is to have its input color space handle retrieved.

## Return value

If the function succeeds, the return value is the current input color space handle.

If this function fails, the return value is **NULL**.

## Remarks

**GetColorSpace** obtains the handle to the input color space regardless of whether color management is enabled for the device context.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)