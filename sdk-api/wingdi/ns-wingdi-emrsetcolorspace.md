# EMRSETCOLORSPACE structure

## Description

The **EMRSETCOLORSPACE**, **EMRSELECTCOLORSPACE**, and **EMRDELETECOLORSPACE** structures contain members for the **SetColorSpace** and **DeleteColorSpace** enhanced metafile records.

## Members

### `emr`

Base structure for all record types.

### `ihCS`

Color space handle index.

## Remarks

There is no function that generates an enhanced metafile record with the **EMRSELECTCOLORSPACE** structure.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)