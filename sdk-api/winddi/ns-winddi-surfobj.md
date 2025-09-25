# SURFOBJ structure

## Description

The SURFOBJ structure is the user object for a surface. A device driver usually calls methods on a surface object only when the surface object represents a GDI bitmap or a [device-managed surface](https://learn.microsoft.com/windows-hardware/drivers/).

## Members

### `dhsurf`

Handle to a surface, provided that the surface is device-managed. Otherwise, this member is zero.

### `hsurf`

Handle to the surface.

### `dhpdev`

Identifies the device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) that is associated with the specified surface.

### `hdev`

GDI's logical handle to the PDEV associated with this device.

### `sizlBitmap`

Specifies a SIZEL structure that contains the width and height, in pixels, of the surface. The SIZEL structure is identical to the [SIZE](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-size) structure.

### `cjBits`

Specifies the size of the buffer pointed to by **pvBits**.

### `pvBits`

If the surface is a standard format bitmap, this is a pointer to the surface's pixels. For BMF_JPEG or BMF_PNG images, this is a pointer to a buffer containing the image data in a JPEG or PNG format. Otherwise, this member is **NULL**.

### `pvScan0`

Pointer to the first scan line of the bitmap. If **iBitmapFormat** is BMF_JPEG or BMF_PNG, this member is **NULL**.

### `lDelta`

Specifies the count of bytes required to move down one scan line in the bitmap. If **iBitmapFormat** is BMF_JPEG or BMF_PNG, this member is **NULL**.

### `iUniq`

Specifies the current state of the specified surface. Every time the surface changes, this value is incremented. This enables drivers to cache source surfaces.

For a surface that should not be cached, **iUniq** is set to zero. This value is used in conjunction with the BMF_DONTCACHE flag of **fjBitmap**.

### `iBitmapFormat`

Specifies the standard format most closely matching this surface. If the **iType** member specifies a bitmap (STYPE_BITMAP), this member specifies its format. NT-based operating systems support a set of predefined formats, although applications can also send device-specific formats by using **SetDIBitsToDevice**. Supported predefined formats include the following:

| Value | Meaning |
| --- | --- |
| BMF_1BPP | 1 bit per pixel. |
| BMF_4BPP | 4 bits per pixel. |
| BMF_8BPP | 8 bits per pixel. |
| BMF_16BPP | 16 bits per pixel. |
| BMF_24BPP | 24 bits per pixel. |
| BMF_32BPP | 32 bits per pixel. |
| BMF_4RLE | 4 bits per pixel, run length encoded. |
| BMF_8RLE | 8 bits per pixel, run length encoded. |
| BMF_JPEG | JPEG compressed image. |
| BMF_PNG | PNG compressed image. |

### `iType`

Surface type, which is one of the following:

| Type | Definition |
| --- | --- |
| STYPE_BITMAP | The surface is a bitmap. |
| STYPE_DEVBITMAP | The surface is a device format bitmap. |
| STYPE_DEVICE | The surface is managed by the device. |

### `fjBitmap`

If the surface is of type STYPE_BITMAP and is a standard uncompressed format bitmap, the following flags can be set. Otherwise, this member should be ignored.

| Value | Meaning |
| --- | --- |
| BMF_DONTCACHE | The bitmap should not be cached by the driver because it is a transient bitmap, created by GDI, that the driver will never see again. If this flag is set, the **iUniq** member of this structure will be set to 0. |
| BMF_KMSECTION | Is used by GDI only and should be ignored by the driver. |
| BMF_NOTSYSMEM | The bitmap is not in system memory. [EngModifySurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmodifysurface) sets this flag when it moves a bitmap into video memory. |
| BMF_NOZEROINIT | The bitmap was not zero-initialized. |
| BMF_TOPDOWN | The first scan line represents the *top* of the bitmap. |
| BMF_WINDOW_BLT | GDI sets this flag to notify the driver of a window move from one screen location to another. |

## Remarks

When information about a particular surface is required by a driver, the driver must access the SURFOBJ. This structure allows quick access to the properties of the surface.

When a SURFOBJ structure represents a GDI bitmap, the driver must be able to determine the format of the bitmap and locate the bitmap bits.

When a SURFOBJ structure represents a device surface, the driver must be able to locate the device handle for the surface.

For more information about supporting JPEG and PNG compressed images, see [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo).