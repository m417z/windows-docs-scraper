# DD_ENDMOCOMPFRAMEDATA structure

## Description

The DD_ENDMOCOMPFRAMEDATA structure contains information required to complete a decoded frame.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current DirectDraw process only.

### `lpMoComp`

Points to a [DD_MOTIONCOMP_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncomp_local) structure that contains a description of the motion compensation being requested.

### `lpInputData`

Points to an optional buffer, the contents of which are defined by the GUID. This buffer cannot contain any embedded pointers.

### `dwInputDataSize`

Indicates the size in bytes of data in **lpInputData**.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompEndFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_endframe) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMoCompEndFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_endframe)