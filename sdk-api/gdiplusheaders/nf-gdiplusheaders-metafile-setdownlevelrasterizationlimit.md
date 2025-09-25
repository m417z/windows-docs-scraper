# Metafile::SetDownLevelRasterizationLimit

## Description

Sets the resolution for certain brush bitmaps that are stored in this metafile.

## Parameters

### `metafileRasterizationLimitDpi` [in]

Type: **UINT**

Non-negative integer that specifies the resolution in dpi. If you set this parameter equal to 0, the resolution is set to match the resolution of the device context handle that was passed to the [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-metafile(constmetafile_)) constructor. If you set this parameter to a value greater than 0 but less than 10, the resolution is left unchanged.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns OK, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The purpose of this method is to prevent metafiles from becoming too large as a result of texture and gradient brushes being stored at high resolution. Suppose you construct a [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) object (for recording an [EmfTypeEmfOnly](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype) metafile) based on the device context of a printer that has a resolution of 600 dpi. Also suppose you create a path gradient brush or a texture brush based on a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object that has a resolution of 96 dpi. If the bitmap that represents that brush is stored in the metafile with a resolution of 96 dpi, it will require much less space than if it is stored with a resolution of 600 dpi.

The default rasterization limit for metafiles is 96 dpi. So if you do not call this method at all, path gradient brush and texture brush bitmaps are stored with a resolution of 96 dpi.

The rasterization limit has an effect on metafiles of type [EmfTypeEmfOnly](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype) and [EmfTypeEmfPlusDual](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype), but it has no effect on metafiles of type [EmfTypeEmfPlusOnly](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype).

#### Examples

The following example constructs a [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) object based on the device context of a printer. The code creates a texture brush based on an a BMP file and then records an ellipse filled with that brush. Assume that the printer has a resolution of 600 dpi and the [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object has a resolution of 96 dpi.

```cpp

// Get a device context for a printer.
HDC hdcPrint = CreateDC(NULL, TEXT("\\\\printserver\\printer1"), NULL, NULL);

// Construct a Metafile object (for recording) based on a 600-DPI printer.
Metafile metafile(L"Metafile.emf", hdcPrint, EmfTypeEmfOnly);
{
   // Create a texture brush based on a 96-DPI bitmap.
   Bitmap bitmap(L"Texture.bmp");
   TextureBrush textureBrush(&bitmap);

   // Set the rasterization limit of the metafile to match the DPI of the
   // printer DC, in this case 600. When the bitmap for the texture brush
   // is stored in the metafile, the bitmap will be expanded by a factor of
   // about 6 horizontally and vertically. That will increase the size of
   // the bitmap by a factor of about 36.
   metafile.SetDownLevelRasterizationLimit(0);

   // Record an ellipse filled with the texture brush.
   Graphics graphics(&metafile);
   graphics.FillEllipse(&textureBrush, 10, 10, 40, 40);
}

// The preceding code, along with a particular 24 x 23 bitmap,
// produced a 114 kilobyte metafile. Passing 96, instead of 0, to the
// SetDownLevelRasterizationLimit method produced a 3.5 kilobyte metafile.

```

## See also

[EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Metafile::GetDownLevelRasterizationLimit](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-getdownlevelrasterizationlimit)

[Recording Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recording-metafiles-use)