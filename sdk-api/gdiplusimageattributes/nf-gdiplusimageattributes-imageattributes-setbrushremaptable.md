# ImageAttributes::SetBrushRemapTable

## Description

The **ImageAttributes::SetBrushRemapTable** method sets the color remap table for the brush category.

## Parameters

### `mapSize` [in]

Type: **UINT**

**INT** that specifies the number of elements in the *map* array.

### `map` [in]

Type: **[ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap)***

Pointer to an array of [ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap) structures.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A color-remap table is an array of [ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap) structures. Each **ColorMap** structure has two [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) objects: one that specifies an old color and one that specifies a corresponding new color. During rendering, any color that matches one of the old colors in the remap table is changed to the corresponding new color.

Calling the **ImageAttributes::SetBrushRemapTable** method has the same effect as passing [ColorAdjustTypeBrush](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) to the [ImageAttributes::SetRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setremaptable) method. The specified remap table applies to items in metafiles that are filled with a brush.

#### Examples

The following example creates an
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object and sets its brush remap table so that red is converted to green.

```cpp

ImageAttributes imageAtt;
ColorMap cMap;
cMap.oldColor = Color(255, 255, 0, 0);  // red
cMap.newColor = Color(255, 0, 255, 0);  // green
imageAtt.SetBrushRemapTable(1, &cMap);
				
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)