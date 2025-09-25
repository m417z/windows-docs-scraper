# DD_KERNELCALLBACKS structure

## Description

The DD_KERNELCALLBACKS structure contains entry pointers to the DirectDraw kernel-mode callback functions that the driver supports.

## Members

### `dwSize`

Specifies the size in bytes of this DD_KERNELCALLBACKS structure.

### `dwFlags`

Indicates what Microsoft DirectDraw kernel callback functions the driver has implemented. For every bit set in **dwFlags**, the driver must initialize the corresponding function pointer member of this structure. This member can be one or more of the following flags:

DDHAL_KERNEL_SYNCSURFACEDATA

DDHAL_KERNEL_SYNCVIDEOPORTDATA

### `SyncSurfaceData`

Points to the driver-supplied [DdSyncSurfaceData](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_kernelcb_syncsurface) callback.

### `SyncVideoPortData`

Points to the driver-supplied [DdSyncVideoPortData](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_kernelcb_syncvideoport) callback.

## Remarks

Entries that the display driver does not use should be set to **NULL**. The driver should initialize this structure when its [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function is called with the GUID_KernelCallbacks GUID.

## See also

[DD_COLORCONTROLCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontrolcallbacks)

[DD_MISCELLANEOUSCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneouscallbacks)

[DD_MOTIONCOMPCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncompcallbacks)

[DD_NTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntcallbacks)

[DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks)

[DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks)

[DD_VIDEOPORTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoportcallbacks)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)

[DdSyncSurfaceData](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_kernelcb_syncsurface)

[DdSyncVideoPortData](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_kernelcb_syncvideoport)