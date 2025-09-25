# DrvCreateDeviceBitmap function

## Description

The **DrvCreateDeviceBitmap** function creates and manages bitmaps.

## Parameters

### `dhpdev`

Handle to the PDEV that describes the physical device that an application has designated as the primary target for a bitmap. The format of the bitmap must be compatible with this physical device.

### `sizl`

Specifies a SIZEL structure that contains the width and height of the bitmap to be created. The **cx** and **cy** members of this structure contain respectively, the bitmap's width and height, in pixels. A SIZEL structure is identical to a [SIZE](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-size) structure.

### `iFormat`

Specifies the bitmap format, which indicates the required number of bits of color information per pixel, and always matches the format of the primary. This value can be one of the following:

| Value | Meaning |
| --- | --- |
| BMF_8BPP | 8 bits per pixel. |
| BMF_16BPP | 16 bits per pixel. |
| BMF_24BPP | 24 bits per pixel. |
| BMF_32BPP | 32 bits per pixel. |

## Return value

The return value is a handle that identifies the created bitmap if the function is successful. If the driver chooses to let GDI create and manage the bitmap, the return value is zero. If an error occurs, the return value is 0xFFFFFFFF, and GDI logs an error code.

## Remarks

If the driver creates the bitmap, it can store it anywhere and in any format. It is assumed that the driver will take into account the specifications of the parameters and provide a bitmap with at least as many bits per pixel as requested.

The contents of the created bitmap are undefined.

This function is optional. If this function is implemented, however, [DrvDeleteDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdeletedevicebitmap) must also be implemented.

## See also

[DrvDeleteDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdeletedevicebitmap)