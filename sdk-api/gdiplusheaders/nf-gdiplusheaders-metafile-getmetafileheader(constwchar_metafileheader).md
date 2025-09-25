# Metafile::GetMetafileHeader(IN const WCHAR,OUT MetafileHeader)

## Description

The **Metafile::GetMetafileHeader** method gets the header.

## Parameters

### `filename` [in]

Type: **const WCHAR***

Pointer to a wide-character string that specifies the name of an existing [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) object that contains the header.

### `header` [out]

Type: **[MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader)***

Pointer to a [MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader) object that receives the header, which contains the attributes of the metafile.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns OK, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)