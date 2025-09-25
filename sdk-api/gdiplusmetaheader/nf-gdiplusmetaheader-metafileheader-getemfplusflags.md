# MetafileHeader::GetEmfPlusFlags

## Description

The **MetafileHeader::GetEmfPlusFlags** method gets a flag that indicates whether the associated metafile was recorded against a video display device context.

## Return value

Type: **UINT**

If the associated metafile is in the EMF+ format and was recorded against a video display device context, then this method returns GDIP_EMFPLUSFLAGS_DISPLAY; otherwise, it returns 0. GDIP_EMFPLUSFLAGS_DISPLAY is defined in Gdiplusmetaheader.h.

## See also

[GetMetafileHeader](https://learn.microsoft.com/previous-versions/ms535280(v=vs.85))

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)