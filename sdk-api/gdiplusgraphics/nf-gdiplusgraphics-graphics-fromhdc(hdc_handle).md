# Graphics::FromHDC(IN HDC,IN HANDLE)

## Description

The **Graphics::FromHDC** method creates a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that is associated with a specified device context and a specified device.

## Parameters

### `hdc` [in]

Type: **HDD**

Handle to the device context that is associated with the new
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

### `hdevice` [in]

Type: **HANDLE**

Handle to a device that is associated with the new
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Return value

Type: **[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

This method returns a pointer to the new
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Remarks

When you use this method to create a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, make sure that the
**Graphics** object is deleted before the device context is released.

## See also

[Changes in the Programming Model](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-changes-in-the-programming-model-about)

[FromHDC Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fromhdc(inhdc))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-graphics(constgraphics_))

[Graphics::FromHWND](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fromhwnd)

[Graphics::FromImage](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fromimage)

[Graphics::GetHDC](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gethdc)

[Optimizing Printing by Providing a Printer Handle](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-optimizing-printing-by-providing-a-printer-handle-use)