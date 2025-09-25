# Graphics::Graphics(IN HDC,IN HANDLE)

## Description

Creates a **Graphics::Graphics** object that is associated with a specified device context and a specified device.

## Parameters

### `hdc` [in]

Type: **HDC**

Handle to a device context that will be associated with the new **Graphics::Graphics** object.

### `hdevice` [in]

Type: **HANDLE**

Handle to a device that will be associated with the new **Graphics::Graphics** object.

## Remarks

When you use this constructor to create a **Graphics::Graphics** object, make sure that the **Graphics::Graphics** object is deleted or goes out of scope before the device context is released.

## See also

[Changes in the Programming Model](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-changes-in-the-programming-model-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-graphics(constgraphics_))

[Optimizing Printing by Providing a Printer Handle](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-optimizing-printing-by-providing-a-printer-handle-use)