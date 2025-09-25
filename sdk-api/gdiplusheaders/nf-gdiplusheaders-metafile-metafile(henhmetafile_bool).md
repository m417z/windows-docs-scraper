# Metafile::Metafile(IN HENHMETAFILE,IN BOOL)

## Description

Creates a Windows GDI+ **Metafile::Metafile** object for playback based on a Windows Graphics Device Interface (GDI) Enhanced Metafile (EMF) file.

## Parameters

### `hEmf` [in]

Type: **HENHMETAFILE**

Windows handle to a metafile.

### `deleteEmf` [in]

Type: **BOOL**

Optional. Boolean value that specifies whether the Windows handle to a metafile is deleted when the **Metafile::Metafile** object is deleted. **TRUE** specifies that the *hEmf* Windows handle is deleted, and **FALSE** specifies that the *hEmf* Windows handle is not deleted. The default value is **FALSE**.

## Remarks

This constructor allows GDI+ to own the windows handle to the metafile, which should not be used by other portions of your code until the **Metafile::Metafile** object is deleted or goes out of scope.

## See also

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Metafile::GetHENHMETAFILE](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-gethenhmetafile)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)

[Recording Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recording-metafiles-use)