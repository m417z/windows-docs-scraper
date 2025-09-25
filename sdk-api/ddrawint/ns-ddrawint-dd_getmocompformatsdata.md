# DD_GETMOCOMPFORMATSDATA structure

## Description

The DD_GETMOCOMPFORMATSDATA structure contains the uncompressed format information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpGuid`

Points to a GUID that describes the uncompressed formats being requested.

### `dwNumFormats`

Indicates the number of uncompressed formats supported for the specified GUID.

### `lpFormats`

Points to a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that contains the motion compensation pixel format. If this member is not **NULL**, the uncompressed formats are copied into the buffer pointed to by this member.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompGetFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getformats) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMoCompGetFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getformats)