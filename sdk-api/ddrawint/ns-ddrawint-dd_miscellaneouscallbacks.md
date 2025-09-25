# DD_MISCELLANEOUSCALLBACKS structure

## Description

The DD_MISCELLANEOUSCALLBACKS structure contains an entry pointer to the memory query callback that a device driver supports.

## Members

### `dwSize`

Specifies the size in bytes of this DD_MISCELLANEOUSCALLBACKS structure.

### `dwFlags`

Indicates whether the device supports the [DdGetAvailDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getavaildrivermemory) callback. The driver sets this member to DDHAL_MISCCB32_GETAVAILDRIVERMEMORY when it implements the callback.

### `GetAvailDriverMemory`

Points to the driver-supplied [DdGetAvailDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getavaildrivermemory) callback.

## Remarks

Entries that the display driver does not use should be set to **NULL**. The driver should initialize this structure when its [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function is called with the GUID_MiscellaneousCallbacks GUID.

## See also

[DD_COLORCONTROLCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontrolcallbacks)

[DD_KERNELCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_kernelcallbacks)

[DD_MOTIONCOMPCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncompcallbacks)

[DD_NTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntcallbacks)

[DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks)

[DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks)

[DD_VIDEOPORTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoportcallbacks)

[DdGetAvailDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getavaildrivermemory)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)