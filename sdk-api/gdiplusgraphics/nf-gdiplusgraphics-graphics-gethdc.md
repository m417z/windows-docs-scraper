# Graphics::GetHDC

## Description

The **Graphics::GetHDC** method gets a handle to the device context associated with this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Return value

Type: **HDC**

This method returns a handle to the device context associated with this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Remarks

Each call to the **Graphics::GetHDC** method of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object should be paired with a call
to the [Graphics::ReleaseHDC](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-releasehdc) method of that same
**Graphics** object. Do not call any methods of the
**Graphics** object between the calls to **Graphics::GetHDC** and **Graphics::ReleaseHDC**. If you attempt to call a method of the
**Graphics** object between **Graphics::GetHDC** and **Graphics::ReleaseHDC**, the method will fail and will return ObjectBusy.

Any state changes you make to the device context between **Graphics::GetHDC** and [Graphics::ReleaseHDC](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-releasehdc) will be ignored by GDI+ and will not be reflected in rendering done by GDI+.

#### Examples

The following function uses GDI+ to draw an ellipse, then uses GDI to draw a rectangle, and finally uses GDI+ to draw a line. The function's one parameter is a pointer to a GDI+
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The code calls the
[Graphics::DrawEllipse](https://learn.microsoft.com/previous-versions/ms536067(v=vs.85)) method of that
**Graphics** object to draw an ellipse. Next, the code calls the **Graphics::GetHDC** method to obtain a handle to the device context associated with the
**Graphics** object. The code draws a rectangle by passing the device context handle to the GDI **Rectangle** function. The code calls the [Graphics::ReleaseHDC](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-releasehdc) method of the
**Graphics** object and then uses the
**Graphics** object to draw a line.

```cpp
VOID Example_GetReleaseHDC(Graphics* g)
{
   Pen pen(Color(255, 0, 0, 255));
   g->DrawEllipse(&pen, 10, 10, 100, 50);  // GDI+

   HDC hdc = g->GetHDC();

      // Make GDI calls, but don't call any methods
      // on g until after the call to ReleaseHDC.
      Rectangle(hdc, 120, 10, 220, 60);  // GDI
   g->ReleaseHDC(hdc);

   // Ok to call methods on g again.
   g->DrawLine(&pen, 240, 10, 340, 60);
}
```

## See also

[Changes in the Programming Model](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-changes-in-the-programming-model-about)

[FromHDC Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fromhdc(inhdc))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-graphics(constgraphics_))

[Graphics::ReleaseHDC](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-releasehdc)