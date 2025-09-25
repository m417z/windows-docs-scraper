# Brush::GetLastStatus

## Description

The **Brush::GetLastStatus** method returns a value that indicates the nature of this
[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **Brush::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this
[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object have failed since the previous call to **Brush::GetLastStatus**, then **Brush::GetLastStatus** returns Ok.

If at least one method invoked on this
[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object has failed since the previous call to **Brush::GetLastStatus**, then **Brush::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **Brush::GetLastStatus** immediately after constructing a
[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object to determine whether the constructor succeeded.

The first time you call the **Brush::GetLastStatus** method of a
[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object, it returns Ok if the constructor succeeded and all methods invoked so far on the
**Brush** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

#### Examples

The following example creates a [SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush) object
**solidBrush** and checks the status of the call used to create
**solidBrush**. Then, if the call was successful, the code uses
**solidBrush** to fill a rectangle.

```cpp
VOID Example_GetLastStatus(HDC hdc)
{
   Graphics graphics(hdc);
   // Create a SolidBrush object.
   SolidBrush solidBrush(Color(255, 0, 255, 0));
   // Get the status of the last call.
   Status lastStatus = solidBrush.GetLastStatus();
   //If the call to create myBrush was successful, use it to fill a rectangle.
   if (lastStatus == Ok)
       graphics.FillRectangle(&solidBrush, Rect(0, 0, 100, 100));
}
```

## See also

[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush)

[TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush)

[Using a Brush to Fill Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-brush-to-fill-shapes-use)