# MetafileHeader::GetVersion

## Description

The **MetafileHeader::GetVersion** method gets the version of the metafile.

## Return value

Type: **UINT**

This method returns the version of the metafile. The metafile version indicates whether the metafile is an EMF, EMF+, or WMF metafile. EMF files always have 0x0010000 as the version. EMF+ files currently have 0xdbc01001 as the version. WMF files usually have 0x0300 as the version; however, earlier versions may be 0x0100.

## See also

[GetMetafileHeader](https://learn.microsoft.com/previous-versions/ms535280(v=vs.85))

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)