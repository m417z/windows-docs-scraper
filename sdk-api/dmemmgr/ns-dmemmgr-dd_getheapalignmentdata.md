# DD_GETHEAPALIGNMENTDATA structure

## Description

The DD_GETHEAPALIGNMENTDATA structure contains data on required alignments from a particular heap.

## Members

### `dwInstance`

Indicates the driver context as returned from the driver initialization routine and stored in the **dhpDev** member of the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure.

### `dwHeap`

Specifies the heap index passed by Microsoft DirectDraw. See the Remarks section for more information.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) callback for a GUID_GetHeapAlignment query. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetHeapAlignment`

Unused on Microsoft Windows 2000 and later versions of the operating system.

### `Alignment`

Points to a [HEAPALIGNMENT](https://learn.microsoft.com/windows/desktop/api/dmemmgr/ns-dmemmgr-heapalignment) structure filled in by the driver.

## Remarks

The **dwHeap** member is the ordinal number of the heap for which alignment data is being requested. In other words, it is the index into the array of [VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory) structures pointed to by the *pvmList* parameter of the [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo) driver function.

## See also

[DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo)

[HEAPALIGNMENT](https://learn.microsoft.com/windows/desktop/api/dmemmgr/ns-dmemmgr-heapalignment)

[VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory)