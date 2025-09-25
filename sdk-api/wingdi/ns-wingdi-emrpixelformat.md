# EMRPIXELFORMAT structure

## Description

The **EMRPIXELFORMAT** structure contains the members for the [SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat) enhanced metafile record. The pixel format information in [ENHMETAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enhmetaheader) refers to this structure.

## Members

### `emr`

The base structure for all record types.

### `pfd`

A
[PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure, which describes the pixel format.

## See also

[ENHMETAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enhmetaheader)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor)

[SetPixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelformat)