# DD_COLORCONTROLCALLBACKS structure

## Description

The DD_COLORCONTROLCALLBACKS structure contains an entry pointer to the Microsoft DirectDraw color control callback that a device driver supports.

## Members

### `dwSize`

Specifies the size in bytes of this DD_COLORCONTROLCALLBACKS structure.

### `dwFlags`

Indicates whether the device supports the color control callback identified by **ColorControl**. The driver should set this member to be DDHAL_COLOR_COLORCONTROL when it implements the color control callback.

### `ColorControl`

Points to the driver-supplied [DdControlColor](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_colorcb_colorcontrol) callback.

## Remarks

Entries that the display driver does not use should be set to **NULL**. The driver should initialize this structure when its [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function is called with the GUID_ColorControlCallbacks GUID.

## See also

[DD_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_callbacks)

[DD_KERNELCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_kernelcallbacks)

[DD_MISCELLANEOUSCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneouscallbacks)

[DD_MOTIONCOMPCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncompcallbacks)

[DD_NTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntcallbacks)

[DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks)

[DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks)

[DD_VIDEOPORTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoportcallbacks)

[DdControlColor](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_colorcb_colorcontrol)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)