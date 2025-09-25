# DD_SURFACECALLBACKS structure

## Description

The DD_SURFACECALLBACKS structure contains entry pointers to the Microsoft DirectDraw surface callback functions that a device driver supports.

## Members

### `dwSize`

Specifies the size in bytes of the DD_SURFACECALLBACKS structure. This member is unused by Microsoft Windows 2000 and later versions.

### `dwFlags`

Indicates which DirectDrawSurface callback functions the driver has implemented. For every bit set in **dwFlags**, the driver must initialize the corresponding function pointer member of this structure. This member can be one or more of the following flags:

DDHAL_SURFCB32_DESTROYSURFACE

DDHAL_SURFCB32_FLIP

DDHAL_SURFCB32_SETCLIPLIST

DDHAL_SURFCB32_LOCK

DDHAL_SURFCB32_UNLOCK

DDHAL_SURFCB32_BLT

DDHAL_SURFCB32_SETCOLORKEY

DDHAL_SURFCB32_ADDATTACHEDSURFACE

DDHAL_SURFCB32_GETBLTSTATUS

DDHAL_SURFCB32_GETFLIPSTATUS

DDHAL_SURFCB32_UPDATEOVERLAY

DDHAL_SURFCB32_SETOVERLAYPOSITION

DDHAL_SURFCB32_SETPALETTE

### `DestroySurface`

Points to the driver-supplied [DdDestroySurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_destroysurface) surface callback.

### `Flip`

Points to the driver-supplied [DdFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_flip) surface callback.

### `SetClipList`

Points to the driver-supplied [DdSetClipList](https://learn.microsoft.com/windows-hardware/drivers/display/windows-vista-display-driver-model-design-guide) surface callback.

### `Lock`

Points to the driver-supplied [DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock) surface callback.

### `Unlock`

Points to the driver-supplied [DdUnlock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_unlock) surface callback.

### `Blt`

Points to the driver-supplied [DdBlt](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_blt) surface callback.

### `SetColorKey`

Points to the driver-supplied [DdSetColorKey](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setcolorkey) surface callback.

### `AddAttachedSurface`

Points to the driver-supplied [DdAddAttachedSurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_addattachedsurface) surface callback.

### `GetBltStatus`

Points to the driver-supplied [DdGetBltStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_getbltstatus) surface callback.

### `GetFlipStatus`

Points to the driver-supplied [DdGetFlipStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_getflipstatus) surface callback.

### `UpdateOverlay`

Points to the driver-supplied [DdUpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_updateoverlay) surface callback.

### `SetOverlayPosition`

Points to the driver-supplied [DdSetOverlayPosition](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setoverlayposition) surface callback.

### `reserved4`

Reserved for system use and should be ignored by the driver.

### `SetPalette`

Points to the driver-supplied [DdSetPalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setpalette) surface callback.

## Remarks

Entries that the display driver does not use should be set to **NULL**. The driver initializes this structure in [DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw).

## See also

[DD_COLORCONTROLCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontrolcallbacks)

[DD_KERNELCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_kernelcallbacks)

[DD_MISCELLANEOUSCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneouscallbacks)

[DD_MOTIONCOMPCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncompcallbacks)

[DD_NTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntcallbacks)

[DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks)

[DD_VIDEOPORTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoportcallbacks)

[DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw)