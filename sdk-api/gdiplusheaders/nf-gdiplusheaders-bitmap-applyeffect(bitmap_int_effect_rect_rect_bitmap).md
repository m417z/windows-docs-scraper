# Bitmap::ApplyEffect(IN Bitmap,IN INT,IN Effect,IN RECT,OUT RECT,OUT Bitmap)

## Description

The **Bitmap::ApplyEffect** method creates a new [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object by applying a specified effect to an existing **Bitmap** object.

## Parameters

### `inputs` [in]

Type: **[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)****

Address of a pointer to a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object to which the effect is applied.

### `numInputs` [in]

Type: **INT**

Integer that specifies the number of input bitmaps. This parameter must be set to 1.

### `effect` [in]

Type: **[Effect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-effect)***

Pointer to an instance of a descendant of the [Effect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-effect) class. The descendant (for example, a [Blur](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-blur) object) specifies the effect that is applied.

### `ROI` [in]

Type: **RECT***

Pointer to a RECT structure that specifies the portion of the input bitmap that is used.

### `outputRect` [out]

Type: **RECT***

Pointer to a RECT structure that receives the portion of the input bitmap that was used. If the rectangle specified by *ROI* lies entirely within the input bitmap, the rectangle returned in *outputRect* is the same as *ROI*. If part of rectangle specified by *ROI* lies outside the input bitmap, then the rectangle returned in *outputRect* is the portion of *ROI* that lies within the input bitmap. Pass **NULL** if you do not want to receive the output rectangle.

### `output` [out]

Type: **[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)****

Address of a variable that receives a pointer to the new [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

**Bitmap::ApplyEffect** returns a pointer to a new [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object. When you have finished using that **Bitmap** object, call [delete](https://learn.microsoft.com/windows/desktop/api/gdiplusbase/nf-gdiplusbase-gdiplusbase-operatordelete) to free the memory that it occupies.

#### Examples

The following example creates two [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) objects: **inputBitmap** and **outputBitmap**. First, **inputBitmap** is constructed from a BMP file. Then **outputBitmap** is created by passing the address of **inputBitmap** to the **Bitmap::ApplyEffect** method. **Bitmap::ApplyEffect** takes the portion of **inputBitmap** specified by **rectOfInterest** and increases the contrast as specified by **briCon**, a [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object.

```cpp
VOID Example_BrightnessContrastApplyEffect2(HDC hdc)
{
   Graphics graphics(hdc);
   Bitmap* inputBitmap = new Bitmap(L"Picture.bmp");
   Bitmap* outputBitmap = NULL;
   RECT rectOfInterest = {10, 12, 100, 80};

   BrightnessContrastParams briConParams;
   briConParams.brightnessLevel = 0;
   briConParams.contrastLevel = 25;
   BrightnessContrast briCon;
   briCon.SetParameters(&briConParams);

   // Draw the original image.
   graphics.DrawImage(inputBitmap, 20, 20);

   // Apply the change in contrast.
   Bitmap::ApplyEffect(
      &inputBitmap, 1, &briCon, &rectOfInterest, NULL, &outputBitmap);

   // Draw the new image.
   graphics.DrawImage(outputBitmap, 200, 20);

   delete inputBitmap;
   delete outputBitmap;
}
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap::ApplyEffect Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap))