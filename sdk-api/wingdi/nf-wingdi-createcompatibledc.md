# CreateCompatibleDC function

## Description

The **CreateCompatibleDC** function creates a memory device context (DC) compatible with the specified device.

## Parameters

### `hdc` [in]

A handle to an existing DC. If this handle is **NULL**, the function creates a memory DC compatible with the application's current screen.

## Return value

If the function succeeds, the return value is the handle to a memory DC.

If the function fails, the return value is **NULL**.

## Remarks

A memory DC exists only in memory. When the memory DC is created, its display surface is exactly one monochrome pixel wide and one monochrome pixel high. Before an application can use a memory DC for drawing operations, it must select a bitmap of the correct width and height into the DC. To select a bitmap into a DC, use the [CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap) function, specifying the height, width, and color organization required.

When a memory DC is created, all attributes are set to normal default values. The memory DC can be used as a normal DC. You can set the attributes; obtain the current settings of its attributes; and select pens, brushes, and regions.

The **CreateCompatibleDC** function can only be used with devices that support raster operations. An application can determine whether a device supports these operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function.

When you no longer need the memory DC, call the [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc) function. We recommend that you call **DeleteDC** to delete the DC. However, you can also call [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) with the HDC to delete the DC.

If *hdc* is **NULL**, the thread that calls **CreateCompatibleDC** owns the HDC that is created. When this thread is destroyed, the HDC is no longer valid. Thus, if you create the HDC and pass it to another thread, then exit the first thread, the second thread will not be able to use the HDC.

**ICM:** If the DC that is passed to this function is enabled for Image Color Management (ICM), the DC created by the function is ICM-enabled. The source and destination color spaces are specified in the DC.

#### Examples

For an example, see [Capturing an Image](https://learn.microsoft.com/windows/desktop/gdi/capturing-an-image).

## See also

[CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap)

[DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)