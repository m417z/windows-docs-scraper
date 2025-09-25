# MetafileHeader::GetWmfHeader

## Description

The **MetafileHeader::GetWmfHeader** method gets a [METAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metaheader) structure that contains properties of the associated metafile.

## Return value

Type: **[METAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metaheader)***

If the associated metafile is in the WMF format, this method returns a pointer to a structure that contains properties of the associated metafile. If the associated metafile is in the EMF or EMF+ format, this method returns **NULL**. The [METAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metaheader) structure is defined in Wingdi.h.

## See also

[GetMetafileHeader](https://learn.microsoft.com/previous-versions/ms535280(v=vs.85))

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)

[METAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metaheader)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)