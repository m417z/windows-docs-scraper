# Metafile::Metafile(IN IStream,IN HDC,IN const RectF &,IN MetafileFrameUnit,IN EmfType,IN const WCHAR)

## Description

Creates a **Metafile::Metafile** object for recording to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface.

## Parameters

### `stream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to a COM [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface that points to a stream of data in a file. When the commands are recorded, they will be saved to this stream.

### `referenceHdc` [in]

Type: **HDC**

Windows handle to a device context that contains attributes of the display device that is used to record the metafile.

### `frameRect` [in, ref]

Type: **const [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)**

Reference to a rectangle that bounds the metafile display.

### `frameUnit` [in]

Type: **[MetafileFrameUnit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-metafileframeunit)**

Optional. Element of the [MetafileFrameUnit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-metafileframeunit) enumeration that specifies the unit of measure for
*frameRect*. The default value is [MetafileFrameUnitGdi](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-metafileframeunit).

### `type` [in]

Type: **[EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype)**

Optional. Element of the [EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype) enumeration that specifies the type of metafile that will be recorded. The default value is [EmfTypeEmfPlusDual](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-metafileframeunit).

### `description` [in]

Type: **const WCHAR***

Optional. Pointer to a wide-character string that specifies the descriptive name of the metafile. The default value is **NULL**.

## Remarks

When recording to a file, the file must be writable, and Windows GDI+ must be able to obtain an exclusive lock on the file.

## See also

[EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype)

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[MetafileFrameUnit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-metafileframeunit)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)

[Recording Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recording-metafiles-use)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)