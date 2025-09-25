# DDMOCOMPBUFFERINFO structure

## Description

The DDMOCOMPBUFFERINFO structure contains the macro block information required to render a frame and passes this information to the [DD_RENDERMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_rendermocompdata) structure.

## Members

### `dwSize`

Specifies the size in bytes of this DDMOCOMPBUFFERINFO structure.

### `lpCompSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that contains the compressed data.

### `dwDataOffset`

Indicates the offset to the relevant data, in bytes, from the beginning of the buffer. This value does not allow for pitch.

### `dwDataSize`

Indicates the size of the relevant data in bytes. This value does not allow for pitch.

### `lpPrivate`

Used by Microsoft DirectDraw and should be ignored by the driver.

## See also

[DD_RENDERMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_rendermocompdata)

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local)