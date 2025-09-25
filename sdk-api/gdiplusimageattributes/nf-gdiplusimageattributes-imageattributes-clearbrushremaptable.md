# ImageAttributes::ClearBrushRemapTable

## Description

The **ImageAttributes::ClearBrushRemapTable** method clears the brush color-remap table of this [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify one color-remap table for the default category, a different color-remap table for the bitmap category, and still a different color-remap table for the brush category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the brush category, then the default settings apply to the brush category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a default remap table that converts red to green and you specify a default gamma value of 1.8. If you call [ImageAttributes::SetBrushRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setbrushremaptable), then the default remap table (red to green) and the default gamma value (1.8) will not apply to brushes. If you later call **ImageAttributes::ClearBrushRemapTable**, the brush category will not revert to the default remap table; rather, the brush category will have no remap table. Similarly, the brush category will not revert to the default gamma value; rather, the brush category will have no gamma value.

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object from a .emf file. The code also creates an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object. The call to [ImageAttributes::SetRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setremaptable) sets the default color-remap table of the **ImageAttributes** object to a table that converts red to blue. The call to [ImageAttributes::SetBrushRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setbrushremaptable) sets the brush remap table of the **ImageAttributes** object to a table that converts red to green.

The code calls [DrawImage](https://learn.microsoft.com/previous-versions/ms536045(v=vs.85)) once to draw the image with no color adjustment. Then the code calls **DrawImage** three more times, each time passing the address of the [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object and the address of the [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object. The second time the image is drawn (after the call to [ImageAttributes::SetRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setremaptable)), all of the red is converted to blue. The third time the image is drawn (after the call to [ImageAttributes::SetBrushRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setbrushremaptable)), all of the red painted with a brush is converted to green, and the rest of the red is converted to blue. The fourth time the image is drawn (after the call to **ImageAttributes::ClearBrushRemapTable**), all the red painted with a brush remains unchanged, and the rest of the red is converted to blue.

```cpp

VOID Example_SetClearBrushRemap(HDC hdc)
{
   Graphics graphics(hdc);

   Image image(L"TestMetafile4.emf");
   ImageAttributes imAtt;

   ColorMap defaultMap;
   defaultMap.oldColor = Color(255, 255, 0, 0);   // red converted to blue
   defaultMap.newColor = Color(255, 0, 0, 255);

   ColorMap brushMap;
   brushMap.oldColor = Color(255, 255, 0, 0);     // red converted to green
   brushMap.newColor = Color(255, 0, 255, 0);

   // Set the default color-remap table.
   imAtt.SetRemapTable(1, &defaultMap, ColorAdjustTypeDefault);

   // Draw the image (metafile) using no color adjustment.
   graphics.DrawImage(
      &image,
      Rect(10, 10, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),          // source rect
      UnitPixel);

   // Draw the image (metafile) using default color adjustment.
   // All red is converted to blue.
   graphics.DrawImage(
      &image,
      Rect(10, 90, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),          // source rect
      UnitPixel,
      &imAtt);

   // Set the brush remap table.
   imAtt.SetBrushRemapTable(1, &brushMap);

   // Draw the image (metafile) using default and brush adjustment.
   // Red painted with a brush is converted to green.
   // All other red is converted to blue (default).
   graphics.DrawImage(
      &image,
      Rect(10, 170, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),           // source rect
      UnitPixel,
      &imAtt);

   // Clear the brush remap table.
   imAtt.ClearBrushRemapTable();

   // Draw the image (metafile) using only default color adjustment.
   // Red painted with a brush gets no color adjustment.
   // All other red is converted to blue (default).
   graphics.DrawImage(
      &image,
      Rect(10, 250, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),           // source rect
      UnitPixel,
      &imAtt);
}
				
```

The preceding code, along with a particular file, Testmetafile4.emf, produced the following output. The ellipses in the left column were drawn with a pen, and the ellipses in the right column were filled with a brush. Note that the default remap table applies to the ellipses drawn with a pen. The remap table that applies to the ellipses filled with a brush varies according to the [ImageAttributes::SetBrushRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setbrushremaptable) and **ImageAttributes::ClearBrushRemapTable** calls.

![Illustration showing four empty ellipses; the first is red and the rest blue, then four filled ellipses: red, blue, green, and red](https://learn.microsoft.com/windows/win32/api/gdiplusimageattributes/images/imageattributesclearbrushremap.png)

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearremaptable)

[ImageAttributes::SetBrushRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setbrushremaptable)

[ImageAttributes::SetRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setremaptable)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)