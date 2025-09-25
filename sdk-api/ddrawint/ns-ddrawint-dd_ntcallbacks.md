# DD_NTCALLBACKS structure

## Description

The DD_NTCALLBACKS structure contains entry pointers to Microsoft Windows 2000 and later Microsoft DirectDraw callback functions that a device driver supports.

## Members

### `dwSize`

Specifies the size in bytes of this DD_NTCALLBACKS structure.

### `dwFlags`

Indicates what Windows 2000 and later callback functions the driver has implemented. For every bit set in **dwFlags**, the driver must initialize the corresponding function pointer member of this structure. This member can be one or more of the following flags:

DDHAL_NTCB32_FREEDRIVERMEMORY

DDHAL_NTCB32_SETEXCLUSIVEMODE

DDHAL_NTCB32_FLIPTOGDISURFACE

### `FreeDriverMemory`

Points to the driver-supplied [DdFreeDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_freedrivermemory) callback.

### `SetExclusiveMode`

Points to the driver-supplied [DdSetExclusiveMode](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_setexclusivemode) callback.

### `FlipToGDISurface`

Points to the driver-supplied [DdFlipToGDISurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_fliptogdisurface) callback.

## Remarks

Entries that the display driver does not use should be set to **NULL**. The driver should initialize this structure when its [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function is called with the GUID_NTCallbacks GUID.

## See also

[DD_COLORCONTROLCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontrolcallbacks)

[DD_KERNELCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_kernelcallbacks)

[DD_MISCELLANEOUSCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneouscallbacks)

[DD_MOTIONCOMPCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncompcallbacks)

[DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks)

[DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks)

[DD_VIDEOPORTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoportcallbacks)

[DdFlipToGDISurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_fliptogdisurface)

[DdFreeDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_freedrivermemory)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)

[DdSetExclusiveMode](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_setexclusivemode)