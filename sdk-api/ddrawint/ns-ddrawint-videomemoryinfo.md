## Description

The VIDEOMEMORYINFO structure describes the general format of the display's memory.

## Members

### `fpPrimary`

Specifies the offset, in bytes, in display memory to the primary surface.

### `dwFlags`

Currently unused and should be set to zero.

### `dwDisplayWidth`

Specifies the current width of the display, in pixels.

### `dwDisplayHeight`

Specifies the current height of the display, in pixels.

### `lDisplayPitch`

Specifies the current pitch of the display, in bytes.

### `ddpfDisplay`

Specifies a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure in which the pixel format of the display is described.

### `dwOffscreenAlign`

Specifies the byte alignment, in bytes, required when allocating this memory for offscreen surfaces.

### `dwOverlayAlign`

Specifies the byte alignment, in bytes, required when allocating this memory for overlay planes.

### `dwTextureAlign`

Specifies the byte alignment, in bytes, required when allocating this memory for textures.

### `dwZBufferAlign`

Specifies the byte alignment, in bytes, required when allocating this memory for the depth buffer.

### `dwAlphaAlign`

Specifies the byte alignment, in bytes, required when allocating this memory for an alpha buffer.

### `pvPrimary`

(Microsoft Windows 2000 and later only)

Specifies a kernel-mode pointer to the beginning of the primary surface.

## Remarks

The VIDEOMEMORYINFO structure has minor differences between Windows 98/Me and Windows 2000 and later. On Windows 2000 and later the data structure is called VIDEOMEMORYINFO and on Windows 98/Me the data structure is called VIDMEMINFO. On Windows 2000 and later, VIDEOMEMORYINFO includes a field **pvPrimary** that stores a kernel-mode pointer to the primary surface. On Windows 98/Me, VIDMEMINFO includes the fields **dwNumHeaps** and **pvmList** that specify an array of memory heaps.

GDI allocates memory for and passes a VIDEOMEMORYINFO structure to the driver's [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo) function as a member of the DD_HALINFO parameter. The driver should fill in the appropriate members to describe the general characteristics of the device's memory.

## See also

[DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo)