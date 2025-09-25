# DD_GETAVAILDRIVERMEMORYDATA structure

## Description

The DD_GETAVAILDRIVERMEMORYDATA structure contains the information needed by the driver to query and return the amount of free memory.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `DDSCaps`

Points to a [DDSCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85)) structure that describes the type of surface for which memory availability is being queried.

### `dwTotal`

Specifies the location in which the driver returns the number of bytes of driver-managed memory that can be used for surfaces of the type described by **DDSCaps**.

### `dwFree`

Specifies the location in which the driver returns the amount of free memory in bytes for the surface type described by **DDSCaps**.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdGetAvailDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getavaildrivermemory) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetAvailDriverMemory`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## See also

[DdGetAvailDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getavaildrivermemory)