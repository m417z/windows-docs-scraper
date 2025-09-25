# DD_UPDATENONLOCALHEAPDATA structure

## Description

The DD_UPDATENONLOCALHEAPDATA structure contains the required heap information.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `dwHeap`

Indicates the ordinal number of the heap for which data is being requested.

### `fpGARTLin`

Points to the linear graphic address remapping table (GART) address of the start of the heap.

### `fpGARTDev`

Points to the physical GART address of the start of the heap.

### `ulPolicyMaxBytes`

Indicates the maximum amount of AGP memory to use.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) callback for a GUID_UpdateNonLocalHeap query. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `UpdateNonLocalHeap`

Unused on Microsoft Windows 2000 and later versions of the operating system.

## See also

[DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)