# Metafile::GetMetafileHeader(HMETAFILE,WmfPlaceableFileHeader*,MetafileHeader*)

## Description

The **Metafile::GetMetafileHeader** method gets the metafile header of this metafile.

## Parameters

### `hWmf`

Window handle to a metafile.

### `wmfPlaceableFileHeader`

Pointer to a placeable metafile header.

### `header`

Pointer to a [MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader) object that receives the copy of the metafile header.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

## See also

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535294(v=vs.85))

[MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader)

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)