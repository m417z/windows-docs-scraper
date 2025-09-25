# DD_RENDERMOCOMPDATA structure

## Description

The DD_RENDERMOCOMPDATA structure contains the information required to render a frame.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpMoComp`

Points to a [DD_MOTIONCOMP_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncomp_local) structure that contains a description of the motion compensation being requested.

### `dwNumBuffers`

Indicates the number of entries in the **lpBufferInfo** member.

### `lpBufferInfo`

Points to a [DDMOCOMPBUFFERINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-ddmocompbufferinfo) structure that contains the surfaces and the locations within the surfaces from which to get the macroblock data to render.

### `dwFunction`

Indicates a specific operation the decoder would like the driver to perform. The possible values for this member are defined by the GUID used during motion compensation. See [DD_CREATEMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createmocompdata) for more information.

### `lpInputData`

Points to an optional input buffer, the contents of which are defined by the GUID. This buffer cannot contain any embedded pointers.

### `dwInputDataSize`

Specifies the size in bytes of the data pointed to by **lpInputData**.

### `lpOutputData`

Points to an optional output buffer, the contents of which are defined by the GUID. This buffer cannot contain any embedded pointers.

### `dwOutputDataSize`

Specifies the size in bytes of the data pointed to by **lpOutputData**.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompRender](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_render) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DD_CREATEMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createmocompdata)

[DdMoCompRender](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_render)