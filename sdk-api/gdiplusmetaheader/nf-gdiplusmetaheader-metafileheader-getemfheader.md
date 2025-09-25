# MetafileHeader::GetEmfHeader

## Description

The **MetafileHeader::GetEmfHeader** method gets an [ENHMETAHEADER3](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-enhmetaheader3) structure that contains properties of the associated metafile.

## Return value

Type: **[ENHMETAHEADER3](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-enhmetaheader3)***

If the associated metafile is in the EMF or EMF+ format, this method returns a pointer to an [ENHMETAHEADER3](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-enhmetaheader3) structure that contains properties of the associated metafile. If the associated metafile is in the WMF format, this method returns **NULL**.

## See also

[ENHMETAHEADER3](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-enhmetaheader3)

[GetMetafileHeader](https://learn.microsoft.com/previous-versions/ms535280(v=vs.85))

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)