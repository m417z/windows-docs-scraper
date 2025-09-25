# DD_BEGINMOCOMPFRAMEDATA structure

## Description

The DDHAL_BEGINMOCOMPFRAMEDATA structure contains the frame information required to start decoding.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpMoComp`

Points to a [DD_MOTIONCOMP_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncomp_local) structure that contains a description of the motion compensation being requested.

### `lpDestSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure representing the destination surface in which to decode this frame.

### `dwInputDataSize`

Indicates the size in bytes of optional input data in **lpInputData** that is required to begin this frame.

### `lpInputData`

Points to an optional input buffer, the contents of which are defined by the GUID. This buffer cannot contain any embedded pointers.

### `dwOutputDataSize`

Indicates the size in bytes of optional output data in **lpOutputData** that is required to begin this frame.

### `lpOutputData`

Points to an optional output buffer, the contents of which are defined by the GUID. This buffer cannot contain any embedded pointers.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompBeginFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_beginframe) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMoCompBeginFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_beginframe)