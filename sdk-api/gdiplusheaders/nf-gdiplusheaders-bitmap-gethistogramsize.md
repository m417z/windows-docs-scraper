# Bitmap::GetHistogramSize

## Description

The **Bitmap::GetHistogramSize** returns the number of elements (in an array of **UINT**s) that you must allocate before you call the [Bitmap::GetHistogram](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-gethistogram) method of a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object.

## Parameters

### `format` [in]

Type: **[HistogramFormat](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-histogramformat)**

Element of the [HistogramFormat](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-histogramformat) enumeration that specifies the pixel format of the bitmap.

### `NumberOfEntries` [out]

Type: **UINT***

Pointer to a **UINT** that receives the number of entries.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)