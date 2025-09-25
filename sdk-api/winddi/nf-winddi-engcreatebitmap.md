# EngCreateBitmap function

## Description

The **EngCreateBitmap** function requests that GDI create and manage a bitmap.

## Parameters

### `sizl`

Specifies a SIZEL structure whose members contain the width and height, in pixels, of the bitmap to be created. A SIZEL structure is identical to a [SIZE](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-size) structure.

If *pvBits* is not **NULL**, this value should represent all pixels visible on the device, allowing the device to keep [off-screen memory](https://learn.microsoft.com/windows-hardware/drivers/).

### `lWidth`

Specifies the allocation width of the bitmap, which is the number of bytes that must be added to a pointer to move down one scan line.

### `iFormat` [in]

Specifies the format of the bitmap in terms of the number of bits of color information per pixel that are required. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| BMF_1BPP | Monochrome |
| BMF_4BPP | 4 bits per pixel |
| BMF_8BPP | 8 bits per pixel |
| BMF_16BPP | 16 bits per pixel |
| BMF_24BPP | 24 bits per pixel |
| BMF_32BPP | 32 bits per pixel |
| BMF_4RLE | 4 bits per pixel; run length encoded |
| BMF_8RLE | 8 bits per pixel; run length encoded |

### `fl` [in]

Is a bitmask that specifies properties about the bitmap to be created. This parameter can be zero, or any combination of the following values:

| Value | Meaning |
| --- | --- |
| BMF_NOZEROINIT | GDI will not zero-initialize the bitmap when allocating it. This flag is checked only when *pvBits* is **NULL**. |
| BMF_TOPDOWN | The first scan line represents the top of the bitmap. Note that standard-format bitmaps have the first scan line at the bottom by default. |
| BMF_USERMEM | GDI will allocate the memory for the bitmap from user memory. By default, the memory is allocated from the kernel's address space. This flag should be specified only when the bitmap being created will not be used by other processes. User memory cannot be passed to [EngWritePrinter](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwriteprinter) by the printer driver. |

### `pvBits` [in]

Pointer to the first scan line of the bitmap that is to be created. If this parameter is **NULL**, GDI allocates the storage space for the pixels of the bitmap. If *pvBits* is not **NULL**, it is a pointer to the buffer for the bitmap.

## Return value

If the function completes successfully, the return value is a handle that identifies the created bitmap. Otherwise, the return value is 0. **EngCreateBitmap** does not log an error code.

## Remarks

Storage for the bitmap can optionally be provided by the driver.

The driver should associate the created bitmap as a surface by calling [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface) before returning from [DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface).

The bitmap should be deleted by using [EngDeleteSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesurface) when it is no longer needed.

Frame buffer display drivers should use the *pvBits* parameter, allowing GDI to do most drawing directly to the display.

## See also

[DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap)

[EngAllocUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocusermem)