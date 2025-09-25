# DD_DESTROYMOCOMPDATA structure

## Description

The DD_DESTROYMOCOMPDATA structure contains the information required to finish performing motion compensation.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpMoComp`

Points to a [DD_MOTIONCOMP_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncomp_local) structure that contains a description of the motion compensation being requested.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompDestroy](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_destroy) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMoCompDestroy](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_destroy)