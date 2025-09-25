# Metafile::GetHENHMETAFILE

## Description

The **Metafile::GetHENHMETAFILE** method gets a Windows handle to an Enhanced Metafile (EMF) file.

## Return value

Type: **HENHMETAFILE**

This method returns a **HENHMETAFILE**.

## Remarks

This method sets the [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) object to an invalid state. The user is responsible for calling DeleteEnhMetafile, to delete the Windows handle.

#### Examples

The following example creates a [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) object from an EMF+ file and gets a Windows handle to the metafile.

```cpp
VOID Example_GetHENHMETAFILE(HDC hdc)
{

   // Create a GDI+ Metafile object from an existing disk file.
   Metafile metafile(L"SampleMetafile.emf+");

   // Get a Windows handle to the metafile.
   HENHMETAFILE hEmf = metafile.GetHENHMETAFILE();

}
```

## See also

[ENHMETAHEADER3](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/ns-gdiplusmetaheader-enhmetaheader3)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)