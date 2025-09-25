# EngCreateDeviceBitmap function

## Description

The **EngCreateDeviceBitmap** function requests GDI to create a handle for a device bitmap.

## Parameters

### `dhsurf` [in]

Device handle to the device bitmap to be created.

### `sizl` [in]

Specifies a SIZEL structure that contains the width and height of the bitmap to be created. The **cx** and **cy** members of this structure contain respectively, the bitmap's width and height, in pixels. A SIZEL structure is identical to a [SIZE](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-size) structure.

### `iFormatCompat`

Specifies the compatible engine format of the device surface being created. This is used by GDI if a temporary buffer is needed to simulate a complicated drawing call. The allowable values for *iFormatCompat* are BMF_1BPP, BMF_4BPP, BMF_8BPP, BMF_16BPP, BMF_24BPP, and BMF_32BPP.

## Return value

The return value is a handle that identifies the bitmap if the function is successful. Otherwise, it is zero, and an error code is logged.

## Remarks

The surface should be associated by using [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface). The bitmap should be deleted by calling [EngDeleteSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesurface) when it is no longer needed.

## See also

[EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap)