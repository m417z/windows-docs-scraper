# Graphics::FromHDC(IN HDC)

## Description

The **Graphics::FromHDC** method creates a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that is associated with a specified device context.

## Parameters

### `hdc` [in]

Type: **HDC**

Handle to the device context that will be associated with the new
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Return value

Type: **[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

This method returns a pointer to the new
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Remarks

When you use this method to create a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, make sure that the
**Graphics** object is deleted before the device context is released.

#### Examples

The following example calls **Graphics::FromHDC** to create a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object and then uses that
**Graphics** object to draw a rectangle.

```cpp
VOID Example_FromHDC(HDC hdc)
{
   Graphics* pGraphics = Graphics::FromHDC(hdc);
   Pen pen(Color(255, 255, 0, 0));
   pGraphics->DrawRectangle(&pen, 10, 10, 200, 100);
   delete pGraphics;
}
```

## See also

[Changes in the Programming Model](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-changes-in-the-programming-model-about)

[FromHDC Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fromhdc(inhdc))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-graphics(constgraphics_))

[Graphics::FromHWND](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fromhwnd)

[Graphics::FromImage](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fromimage)

[Graphics::GetHDC](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gethdc)