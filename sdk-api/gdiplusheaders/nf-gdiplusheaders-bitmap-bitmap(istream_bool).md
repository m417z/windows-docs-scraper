# Bitmap::Bitmap(IN IStream,IN BOOL)

## Description

Creates a **Bitmap::Bitmap** object based on an **IStream** COM interface.

## Parameters

### `stream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to an
**IStream** COM interface.

### `useEmbeddedColorManagement` [in]

Type: **BOOL**

Boolean value that specifies whether the new **Bitmap::Bitmap** object applies color correction according to color management information that is embedded in the stream (represented by the **stream** parameter). Embedded information can include International Color Consortium (ICC) profiles, gamma values, and chromaticity information. **TRUE** specifies that color correction is enabled, and **FALSE** specifies that color correction is not enabled. The default value is **FALSE**.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap Constructors](https://msdn.microsoft.com/9b246a76-e8c0-41b2-9bb2-0df06ebc5563)

[Bitmap::FromStream](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-fromstream)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)