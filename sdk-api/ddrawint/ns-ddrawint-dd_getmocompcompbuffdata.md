# DD_GETMOCOMPCOMPBUFFDATA structure

## Description

The DD_GETMOCOMPCOMPBUFFDATA structure contains the compressed buffer information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpGuid`

Points to a GUID for which the compressed buffer information is requested.

### `dwWidth`

Indicates the width in pixels of the uncompressed output frame.

### `dwHeight`

Indicates the height in pixels of the uncompressed output frame.

### `ddPixelFormat`

Points to a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that contains the pixel format of the uncompressed output frame.

### `dwNumTypesCompBuffs`

Indicates how many different types of surfaces the driver requires to perform motion compensation using the requested GUID.

### `lpCompBuffInfo`

Points to a [DDCOMPBUFFERINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-ddcompbufferinfo) structure that contains the driver-supplied information for each type of required surface.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompGetBuffInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getcompbuffinfo) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMoCompGetBuffInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getcompbuffinfo)