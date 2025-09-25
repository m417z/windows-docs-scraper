# Metafile::Metafile(IN const WCHAR,IN const WmfPlaceableFileHeader)

## Description

This topic lists the constructors of the
[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) class. For a complete class listing, see **Metafile Class**.

### Overload list

| Constructor | Description |
| --- | --- |
| [Metafile(WCHAR*)](https://learn.microsoft.com/previous-versions/ms535285(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535285(v=vs.85)) object for playback. |
| [Metafile(IStream*)](https://learn.microsoft.com/previous-versions/ms535294(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535294(v=vs.85)) object from an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface for playback. |
| [Metafile(HENHMETAFILE,BOOL)](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-metafile(inhenhmetafile_inbool)) | Creates a GDI+ [Metafile::Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-metafile(inhenhmetafile_inbool)) object for playback based on a GDI Enhanced Metafile (EMF) file. |
| [Metafile(HDC,EmfType,WCHAR*)](https://learn.microsoft.com/previous-versions/ms535284(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535284(v=vs.85)) object for recording. |
| [Metafile(WCHAR*,HDC,EmfType,WCHAR*)](https://learn.microsoft.com/previous-versions/ms535293(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535293(v=vs.85)) object for recording. |
| [Metafile(IStream*,HDC,EmfType,WCHAR*)](https://learn.microsoft.com/previous-versions/ms535290(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535290(v=vs.85)) object for recording to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. |
| [Metafile(HMETAFILE,WmfPlaceableFileHeader*,BOOL)](https://learn.microsoft.com/previous-versions/ms535287(v=vs.85)) | Creates a GDI+[Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535287(v=vs.85)) object for recording. The format will be placeable metafile. |
| [Metafile(HDC,Rect&,MetafileFrameUnit,EmfType,WCHAR*)](https://learn.microsoft.com/previous-versions/ms535296(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535296(v=vs.85)) object for recording. |
| [Metafile(HDC,RectF&,MetaFileFrameUnit,EmfType,WCHAR*)](https://learn.microsoft.com/previous-versions/ms535286(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535286(v=vs.85)) object for recording. |
| [Metafile(WCHAR*,HDC,Rect&,MetaFileFrameUnit,EmfType,WCHAR*)](https://learn.microsoft.com/previous-versions/ms535288(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535288(v=vs.85)) object for recording. |
| [Metafile(WCHAR*,HDC,RectF&,MetafileFrameUnit,EmfType,WCHAR*)](https://learn.microsoft.com/previous-versions/ms535292(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535292(v=vs.85)) object for recording. |
| [Metafile(IStream*,HDC,Rect&,MetafileFrameUnit,EmfType,WCHAR*)](https://learn.microsoft.com/previous-versions/ms535291(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535291(v=vs.85)) object for recording to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. |
| [Metafile(IStream*,HDC,RectF&,MetafileFrameUnit,EmfType,WCHAR*)](https://learn.microsoft.com/previous-versions/ms535289(v=vs.85)) | Creates a [Metafile::Metafile](https://learn.microsoft.com/previous-versions/ms535289(v=vs.85)) object for recording to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. |

## Parameters