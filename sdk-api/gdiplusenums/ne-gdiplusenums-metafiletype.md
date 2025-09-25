# MetafileType enumeration

## Description

The **MetafileType** enumeration specifies types of metafiles. The
[MetafileHeader::GetType](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nf-gdiplusmetaheader-metafileheader-gettype) method returns an element of this enumeration.

## Constants

### `MetafileTypeInvalid`

Specifies a metafile format that is not recognized in GDI+.

### `MetafileTypeWmf`

Specifies a WMF file. Such a file contains only GDI records.

### `MetafileTypeWmfPlaceable`

Specifies a WMF file that has a placeable metafile header in front of it.

### `MetafileTypeEmf`

Specifies an EMF file. Such a file contains only GDI records.

### `MetafileTypeEmfPlusOnly`

Specifies an EMF+ file. Such a file contains only GDI+ records and must be displayed by using GDI+. Displaying the records using GDI may cause unpredictable results.

### `MetafileTypeEmfPlusDual`

Specifies an EMF+ Dual file. Such a file contains GDI+ records along with alternative GDI records and can be displayed by using either GDI or GDI+. Displaying the records using GDI may cause some quality degradation.

## See also

[MetafileHeader::GetType](https://learn.microsoft.com/windows/desktop/api/gdiplusmetaheader/nf-gdiplusmetaheader-metafileheader-gettype)