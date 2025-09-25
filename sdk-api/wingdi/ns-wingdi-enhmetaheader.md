# ENHMETAHEADER structure

## Description

The **ENHMETAHEADER** structure contains enhanced-metafile data such as the dimensions of the picture stored in the enhanced metafile,
the count of records in the enhanced metafile, the resolution of the device on which the picture was created, and so on.

This structure is always the first record in an enhanced
metafile.

## Members

### `iType`

The record type. This member must specify the value assigned to the EMR_HEADER constant.

### `nSize`

The structure size, in bytes.

### `rclBounds`

The dimensions, in device units, of the smallest rectangle that can be drawn around the picture stored in the metafile.
This rectangle is supplied by graphics device interface (GDI). Its dimensions include the right and bottom edges.

### `rclFrame`

The dimensions, in .01 millimeter units, of a rectangle that surrounds the picture stored in the metafile.
This rectangle must be supplied by the application that creates the metafile. Its dimensions include the right and bottom edges.

### `dSignature`

A signature. This member must specify the value assigned to the ENHMETA_SIGNATURE constant.

### `nVersion`

The metafile version. The current version value is 0x10000.

### `nBytes`

The size of the enhanced metafile, in bytes.

### `nRecords`

The number of records in the enhanced metafile.

### `nHandles`

The number of handles in the enhanced-metafile handle table. (Index zero in this table is reserved.)

### `sReserved`

Reserved; must be zero.

### `nDescription`

The number of characters in the array that contains the description of the enhanced metafile's contents.
This member should be set to zero if the enhanced metafile does not contain a description string.

### `offDescription`

The offset from the beginning of the **ENHMETAHEADER** structure to the array that contains the description of the enhanced metafile's contents.
This member should be set to zero if the enhanced metafile does not contain a description string.

### `nPalEntries`

The number of entries in the enhanced metafile's palette.

### `szlDevice`

The resolution of the reference device, in pixels.

### `szlMillimeters`

The resolution of the reference device, in millimeters.

### `cbPixelFormat`

The size of the last recorded pixel format in a metafile.
If a pixel format is set in a reference DC at the start of recording, *cbPixelFormat* is set to the size of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor).
When no pixel format is set when a metafile is recorded, this member is set to zero.
If more than a single pixel format is set, the header points to the last pixel format.

### `offPixelFormat`

The offset of pixel format used when recording a metafile.
If a pixel format is set in a reference DC at the start of recording or during recording,
*offPixelFormat* is set to the offset of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) in the metafile.
If no pixel format is set when a metafile is recorded, this member is set to zero.
If more than a single pixel format is set, the header points to the last pixel format.

### `bOpenGL`

Indicates whether any OpenGL records are present in a metafile.
*bOpenGL* is a simple Boolean flag that you can use to determine whether an enhanced metafile requires OpenGL handling.
When a metafile contains OpenGL records, *bOpenGL* is **TRUE**; otherwise it is **FALSE**.

### `szlMicrometers`

The size of the reference device, in micrometers.

## See also

[ENHMETARECORD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enhmetarecord)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)