# DD_MOTIONCOMPCALLBACKS structure

## Description

The DD_MOTIONCOMPCALLBACKS structure contains entry pointers to the motion compensation callback functions that a device driver supports.

## Members

### `dwSize`

Specifies the size in bytes of this DD_MOTIONCOMPCALLBACKS structure.

### `dwFlags`

Indicates what additional Microsoft DirectDraw motion compensation callback functions the driver has implemented. For every bit set in **dwFlags**, the driver must initialize the corresponding function pointer member of this structure. This member can be one or more of the following flags:

DDHAL_MOCOMP32_BEGINFRAME

DDHAL_MOCOMP32_CREATE

DDHAL_MOCOMP32_DESTROY

DDHAL_MOCOMP32_GETCOMPBUFFINFO

DDHAL_MOCOMP32_GETINTERNALINFO

DDHAL_MOCOMP32_ENDFRAME

DDHAL_MOCOMP32_GETFORMATS

DDHAL_MOCOMP32_GETGUIDS

DDHAL_MOCOMP32_QUERYSTATUS

DDHAL_MOCOMP32_RENDER

### `GetMoCompGuids`

Points to the driver-supplied [DdMoCompGetGuids](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getguids) callback function.

### `GetMoCompFormats`

Points to the driver-supplied [DdMoCompGetFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getformats) callback function.

### `CreateMoComp`

Points to the driver-supplied [DdMoCompCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_create) callback function.

### `GetMoCompBuffInfo`

Points to the driver-supplied [DdMoCompGetBuffInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getcompbuffinfo) callback function.

### `GetInternalMoCompInfo`

Points to the driver-supplied [DdMoCompGetInternalInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getinternalinfo) callback function.

### `BeginMoCompFrame`

Points to the driver-supplied [DdMoCompBeginFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_beginframe) callback function.

### `EndMoCompFrame`

Points to the driver-supplied [DdMoCompEndFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_endframe) callback function.

### `RenderMoComp`

Points to the driver-supplied [DdMoCompRender](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_render) callback function.

### `QueryMoCompStatus`

Points to the driver-supplied [DdMoCompQueryStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_querystatus) callback function.

### `DestroyMoComp`

Points to the driver-supplied [DdMoCompDestroy](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_destroy) callback function.

## Remarks

Entries that the display driver does not use should be set to **NULL**. The driver should initialize this structure when its [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function is called with the GUID_MotionCompCallbacks GUID.

## See also

[DD_COLORCONTROLCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontrolcallbacks)

[DD_KERNELCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_kernelcallbacks)

[DD_MISCELLANEOUSCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneouscallbacks)

[DD_NTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntcallbacks)

[DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks)

[DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks)

[DD_VIDEOPORTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoportcallbacks)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)

[DdMoCompBeginFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_beginframe)

[DdMoCompCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_create)

[DdMoCompDestroy](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_destroy)

[DdMoCompEndFrame](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_endframe)

[DdMoCompGetBuffInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getcompbuffinfo)

[DdMoCompGetFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getformats)

[DdMoCompGetGuids](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getguids)

[DdMoCompGetInternalInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getinternalinfo)

[DdMoCompQueryStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_querystatus)

[DdMoCompRender](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_render)