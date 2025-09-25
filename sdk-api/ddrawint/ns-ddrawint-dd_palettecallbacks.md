# DD_PALETTECALLBACKS structure

## Description

The DD_PALETTECALLBACKS structure contains entry pointers to the DirectDraw palette callback functions that a device driver supports.

## Members

### `dwSize`

Specifies the size in bytes of this DD_PALETTECALLBACKS structure.

### `dwFlags`

Indicates what DirectDrawPalette callback functions the driver has implemented. For every bit set in **dwFlags**, the driver must initialize the corresponding function pointer member of this structure. This member can be one or more of the following flags:

DDHAL_PALCB32_DESTROYPALETTE

DDHAL_PALCB32_SETENTRIES

### `DestroyPalette`

Points to the driver-supplied [DdDestroyPalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_palcb_destroypalette) palette callback.

### `SetEntries`

Points to the driver-supplied [DdSetEntries](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_palcb_setentries) palette callback.

## Remarks

Entries that the display driver does not use should be set to **NULL**. The driver initializes this structure in [DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw).

## See also

[DD_COLORCONTROLCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontrolcallbacks)

[DD_KERNELCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_kernelcallbacks)

[DD_MISCELLANEOUSCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneouscallbacks)

[DD_MOTIONCOMPCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncompcallbacks)

[DD_NTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntcallbacks)

[DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks)

[DD_VIDEOPORTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoportcallbacks)

[DdDestroyPalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_palcb_destroypalette)

[DdSetEntries](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_palcb_setentries)

[DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw)