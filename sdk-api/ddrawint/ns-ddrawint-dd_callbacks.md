# DD_CALLBACKS structure

## Description

The DD_CALLBACKS structure contains entry pointers to the callback functions that a device driver supports.

## Members

### `dwSize`

Specifies the size in bytes of this structure.

### `dwFlags`

Indicates what Microsoft DirectDraw callback functions the driver has implemented. For every bit set in **dwFlags**, the driver must initialize the corresponding function pointer member of this structure. This member can be one or more of the following flags:

DDHAL_CB32_CANCREATESURFACE

DDHAL_CB32_CREATEPALETTE

DDHAL_CB32_CREATESURFACE

DDHAL_CB32_GETSCANLINE

DDHAL_CB32_MAPMEMORY

DDHAL_CB32_SETCOLORKEY

DDHAL_CB32_SETMODE

DDHAL_CB32_WAITFORVERTICALBLANK

### `DestroyDriver`

Unused on Microsoft Windows 2000 and later and should be ignored by the driver.

### `CreateSurface`

Points to the driver-supplied [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)) callback.

### `SetColorKey`

Points to the driver-supplied [DdSetColorKey](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setcolorkey) callback.

### `SetMode`

Unused on Windows 2000 and later and should be ignored by the driver.

### `WaitForVerticalBlank`

Points to the driver-supplied [DdWaitForVerticalBlank](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_waitforverticalblank) callback.

### `CanCreateSurface`

Points to the driver-supplied [DdCanCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549213(v=vs.85)) callback.

### `CreatePalette`

Points to the driver-supplied [DdCreatePalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createpalette) callback.

### `GetScanLine`

Points to the driver-supplied [DdGetScanLine](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getscanline) callback.

### `MapMemory`

Points to the driver-supplied [DdMapMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mapmemory) callback.

## Remarks

Entries that the display driver does not use should be set to **NULL**. GDI allocates the memory for this structure and calls the driver's [DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw) function to initialize it.

## See also

[DD_COLORCONTROLCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontrolcallbacks)

[DD_KERNELCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_kernelcallbacks)

[DD_MISCELLANEOUSCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneouscallbacks)

[DD_MOTIONCOMPCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncompcallbacks)

[DD_NTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntcallbacks)

[DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks)

[DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks)

[DD_VIDEOPORTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoportcallbacks)

[DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw)