# Metafile::Metafile(IN const WCHAR,IN HDC,IN EmfType,IN const WCHAR)

## Description

Creates a **Metafile::Metafile** object for recording.

## Parameters

### `fileName` [in]

Type: **const WCHAR***

Pointer to a wide-character string that specifies the name of the file in which the metafile will be saved.

### `referenceHdc` [in]

Type: **HDC**

Windows handle to a device context that contains attributes of a display device.

### `type` [in]

Type: **[EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype)**

Optional. Element of the [EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype) enumeration that specifies the type of metafile that will be recorded. The default value is [EmfTypeEmfPlusDual](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype).

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