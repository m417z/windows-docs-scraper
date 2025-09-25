# ApplyEffect(Effect*,RECT*)

## Description

The **Bitmap::ApplyEffect** method alters this [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object by applying a specified effect.

## Parameters

### `effect`

Pointer to an instance of a descendant of the [Effect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-effect) class.
The descendant (for example, a [Blur](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-blur) object) specifies the effect that is applied.

### `ROI`

Pointer to a **RECT** structure that specifies the portion of the input bitmap to which the effect is applied.
Pass **NULL** to specify that the effect applies to the entire input bitmap.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

#### Examples

The following example draws an image twice: once with no change, and once after the brightness has been increased for part of the image.

```cpp
VOID Example_BrightnessContrastApplyEffect1(HDC hdc)
{
   Graphics graphics(hdc);
   Bitmap myBitmap(L"Picture.bmp");
   UINT srcWidth = myBitmap.GetWidth();
   UINT srcHeight = myBitmap.GetHeight();

   BrightnessContrastParams briConParams;
   briConParams.brightnessLevel = 50;
   briConParams.contrastLevel = 0;
   BrightnessContrast briCon;
   briCon.SetParameters(&briConParams);
   RECT rectOfInterest = {20, 15, 80, 50};

   // Draw the original image.
   graphics.DrawImage(&myBitmap, 20, 20, srcWidth, srcHeight);

   // Increase the brightness in a portion of the image.
   myBitmap.ApplyEffect(&briCon, &rectOfInterest);

   // Draw the image again.
   graphics.DrawImage(&myBitmap, 200, 20, srcWidth, srcHeight);
}
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)