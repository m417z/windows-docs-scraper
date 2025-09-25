# DD_GETINTERNALMOCOMPDATA structure

## Description

The DD_GETINTERNALMOCOMPDATA structure contains the internal memory requirements.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpGuid`

Points to a GUID for which the internal memory requirement is requested.

### `dwWidth`

Indicates the width in pixels of uncompressed output frame.

### `dwHeight`

Indicates the height in pixels of uncompressed output frame.

### `ddPixelFormat`

Points to a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that contains the pixel format of the uncompressed output frame.

### `dwScratchMemAlloc`

Indicates the size in bytes of internal memory that the display driver privately reserves to perform motion compensation

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompGetInternalInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getinternalinfo) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMoCompGetInternalInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getinternalinfo)