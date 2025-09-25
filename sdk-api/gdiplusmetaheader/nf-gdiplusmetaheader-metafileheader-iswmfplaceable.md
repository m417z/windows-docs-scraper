# MetafileHeader::IsWmfPlaceable

## Description

The **MetafileHeader::IsWmfPlaceable** method determines whether the associated metafile is a placeable metafile.

## Return value

Type: **BOOL**

If the associated metafile is a placeable metafile, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

Placeable metafiles are .wmf files that contain a preheader preceding the metafile header. The preheader contains additional information for the metafile header of the metafile.

#### Examples

The following example creates a
[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) object from a .wmf file and gets the metafile header of the metafile. The code then determines whether the metafile is a placeable metafile.

```cpp

MetafileHeader metaHeader;
Metafile::GetMetafileHeader(L"sampleMetafile.wmf", &metaHeader);

if(metaHeader.IsWmfPlaceable() == TRUE)
{
   // The associated metafile is a placeable metafile.
}
				
```

## See also

[EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype)

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)

[MetafileHeader](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nl-gdiplusmetaheader-metafileheader)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)