# DD_DIRECTDRAW_GLOBAL structure

## Description

The DD_DIRECTDRAW_GLOBAL structure contains driver information that describes the driver's device.

## Members

### `dhpdev`

Handle to the driver's private [PDEV](https://learn.microsoft.com/windows-hardware/drivers/).

### `dwReserved1`

Reserved for use by the display driver.

### `dwReserved2`

Reserved for use by the display driver.

### `lpDDVideoPortCaps`

Points to an array of one or more [DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps) structures in which the driver should describe the DirectDraw [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) objects that it supports. The structures are allocated by DirectDraw; the number of structures is based on the value returned in the **dwMaxVideoPort** member of [DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps).

This member is **NULL** when the driver does not implement the VPE.

## Remarks

DirectDraw allocates memory for this structure. Only one DD_DIRECTDRAW_GLOBAL definition exists per device. In a multimonitor system, each device has its own unique DD_DIRECTDRAW_GLOBAL structure.

The **dwReserved1** and **dwReserved2** members can be used as required by the driver. For example, a driver might store pointers to internal data structures in these members.

## See also

[DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local)