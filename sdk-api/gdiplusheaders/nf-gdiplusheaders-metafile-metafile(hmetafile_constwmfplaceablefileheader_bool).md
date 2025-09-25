# Metafile::Metafile(IN HMETAFILE,IN const WmfPlaceableFileHeader,IN BOOL)

## Description

Creates a Windows GDI+**Metafile::Metafile** object for recording. The format will be placeable metafile.

## Parameters

### `hWmf` [in]

Type: **HMETAFILE**

Windows handle to a metafile.

### `wmfPlaceableFileHeader` [in]

Type: **const [WmfPlaceableFileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-wmfplaceablefileheader)***

Pointer to a [WmfPlaceableFileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-wmfplaceablefileheader) structure that specifies a preheader preceding the metafile header.

### `deleteWmf` [in]

Type: **BOOL**

Optional. **BOOL** value that specifies whether the Windows handle to a metafile is deleted when the metafile is deleted. **TRUE** specifies that the *hWmf* Windows handle is deleted, and **FALSE** specifies that the *hWmf* Windows handle is not deleted. The default value is **FALSE**.

## Remarks

Placeable metafiles are WMF files that contain a preheader preceding the metafile header. The preheader contains additional information for the metafile header of the metafile.

## See also

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[PWMFRect16](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-pwmfrect16)