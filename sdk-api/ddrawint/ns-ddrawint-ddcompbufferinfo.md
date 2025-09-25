# DDCOMPBUFFERINFO structure

## Description

The DDCOMPBUFFERINFO structure contains driver-supplied information regarding compression buffers.

## Members

### `dwSize`

Specifies the size in bytes of this DDCOMPBUFFERINFO structure.

### `dwNumCompBuffers`

Indicates the number of surfaces of this type required for decompression.

### `dwWidthToCreate`

Indicates the width in pixels of the surface of this type to create.

### `dwHeightToCreate`

Indicates the height in pixels of the surface of this type to create.

### `dwBytesToAllocate`

Indicates the total number of bytes used by each surface.

### `ddCompCaps`

Points to a [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure that contains the capabilities to use when creating surfaces of this type. This allows the driver to specify the type of memory to use when creating these surfaces.

### `ddPixelFormat`

Points to a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that contains the pixel formats to use when creating surfaces of this type.

## Remarks

This structure passes this information to the [DD_GETMOCOMPCOMPBUFFDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getmocompcompbuffdata) structure.