# ImageAttributes::ClearNoOp

## Description

The **ImageAttributes::ClearNoOp** method clears the NoOp setting for a specified category.

## Parameters

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the NoOp setting is cleared. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

You can disable color adjustment for a certain object type by calling the [ImageAttributes::SetNoOp](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setnoop) method. Later, you can reinstate color adjustment for that object type by calling the **ImageAttributes::ClearNoOp** method. For example, the following statement disables color adjustment for brushes:

`myImageAttributes.SetNoOp(ColorAdjustTypeBrush);`

The following statement reinstates the brush color adjustment that was in place before the call to [ImageAttributes::SetNoOp](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setnoop):

`myImageAttributes.ClearNoOp(ColorAdjustTypeBrush);`

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object from a .emf file. The code also creates an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object. The [ImageAttributes::SetColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrix) call sets the brush color-adjustment matrix of that **ImageAttributes** object to a matrix that converts red to green.

The code calls [DrawImage](https://learn.microsoft.com/previous-versions/ms536037(v=vs.85)) three times, each time passing the address of the [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object and the address of the [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object. When the image is drawn the first time, all the red painted by brushes is converted to green. (The red drawn by pens is not changed.) Before the image is drawn the second time, the code calls the [ImageAttributes::SetNoOp](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setnoop) method of the **ImageAttributes** object. So when the image is drawn the second time, no color adjustment is applied to brushes. Before the image is drawn the third time, the code calls the **ImageAttributes::ClearNoOp** method, which reinstates the brush color-adjustment settings. So when the image is drawn the third time, all the red painted by brushes is converted to green.

```cpp

VOID Example_SetClearNoOp(HDC hdc)
{
   Graphics graphics(hdc);

   Image image(L"TestMetafile4.emf");
   ImageAttributes imAtt;

    ColorMatrix brushMatrix = {     // red converted to green
      0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

   imAtt.SetColorMatrix(
      &brushMatrix,
      ColorMatrixFlagsDefault,
      ColorAdjustTypeBrush);

   // Draw the image (metafile) using brush color adjustment.
   // Items filled with a brush change from red to green.
   graphics.DrawImage(
      &image,
      Rect(0, 0, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),        // source rect
      UnitPixel,
      &imAtt);

   // Temporarily disable brush color adjustment.
   imAtt.SetNoOp(ColorAdjustTypeBrush);

   // Draw the image (metafile) without brush color adjustment.
   // There is no change from red to green.
   graphics.DrawImage(
      &image,
      Rect(0, 80, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),          // source rect
      UnitPixel,
      &imAtt);

   // Reinstate brush color adjustment.
   imAtt.ClearNoOp(ColorAdjustTypeBrush);

   // Draw the image (metafile) using brush color adjustment.
   // Items filled with a brush change from red to green.
   graphics.DrawImage(
      &image,
      Rect(0, 160, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),          // source rect
      UnitPixel,
      &imAtt);
}
				
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::Reset](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-reset)

[ImageAttributes::SetNoOp](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setnoop)

[ImageAttributes::SetToIdentity](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-settoidentity)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)