# DD_CREATEMOCOMPDATA structure

## Description

The DD_CREATEMOCOMPDATA structure contains the data required to begin using motion compensation.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpMoComp`

Points to a [DD_MOTIONCOMP_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncomp_local) structure that contains a description of the motion compensation object.

### `lpGuid`

Points to a GUID that describes the motion compensation process being used.

### `dwUncompWidth`

Specifies the width in pixels of the uncompressed output frame.

### `dwUncompHeight`

Specifies the height in pixels of the uncompressed output frame.

### `ddUncompPixelFormat`

Points to a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that contains the format of the uncompressed output frame.

### `lpData`

Points to an optional data buffer that contains any optional information required by the GUID given in **lpGuid**. This buffer cannot contain any embedded pointers.

### `dwDataSize`

Indicates the size in bytes of the data buffer contained in **lpData**.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_create) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMoCompCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_create)