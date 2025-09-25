# EmfType enumeration

## Description

The **EmfType** enumeration specifies the nature of the records that are placed in an Enhanced Metafile (EMF) file. This enumeration is used by several constructors in the
[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) class.

## Constants

### `EmfTypeEmfOnly`

Specifies that all of the records in the metafile are EMF records, which can be displayed by GDI or GDI+.

### `EmfTypeEmfPlusOnly`

Specifies that all of the records in the metafile are EMF+ records, which can be displayed by GDI+ but not by GDI.

### `EmfTypeEmfPlusDual`

Specifies that all EMF+ records in the metafile are associated with an alternate EMF record. Metafiles of type EmfTypeEmfPlusDual can be displayed by GDI or by GDI+.

## See also

[Metafile Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-metafile(constmetafile_))