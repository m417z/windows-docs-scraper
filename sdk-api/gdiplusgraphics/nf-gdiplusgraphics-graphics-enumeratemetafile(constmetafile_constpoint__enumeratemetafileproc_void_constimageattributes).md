# Graphics::EnumerateMetafile(IN const Metafile,IN const Point &,IN EnumerateMetafileProc,IN VOID,IN const ImageAttributes)

## Description

The **Graphics::EnumerateMetafile** method calls an application-defined callback function for each record in a specified metafile. You can use this method to display a metafile by calling
[PlayRecord](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-playrecord) in the callback function.

## Parameters

### `metafile` [in]

Type: **const [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)***

Pointer to a metafile to be enumerated.

### `destPoint` [in, ref]

Type: **const [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)**

Reference to a point that specifies the upper-left corner of the displayed metafile.

### `callback` [in]

Type: **EnumerateMetafileProc**

Pointer to an application-defined callback function. The prototype for the callback function is given in Gdiplustypes.h.

### `callbackData` [in]

Type: **VOID***

Optional. Pointer to a block of data that is passed to the callback function. The default value is **NULL**.

### `imageAttributes` [in]

Type: **[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)***

Optional. Pointer to an
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object that specifies color adjustments for the displayed metafile. The default value is **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.