# DrvGetDirectDrawInfo function

## Description

The **DrvGetDirectDrawInfo** function returns the capabilities of the graphics hardware.

## Parameters

### `dhpdev`

Handle to the [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) returned by the driver's [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) routine.

### `pHalInfo`

Points to a [DD_HALINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_halinfo) structure in which the driver should return the hardware capabilities that it supports.

### `pdwNumHeaps`

Points to the location in which the driver should return the number of VIDEOMEMORY structures pointed to by *pvmList*.

### `pvmList`

Points to an array of [VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory) structures in which the driver should return information about each display memory chunk that it controls. The driver should ignore this parameter when it is **NULL**.

### `pdwNumFourCCCodes`

Points to the location in which the driver should return the number of DWORDs pointed to by *pdwFourCC*.

### `pdwFourCC`

Points to an array of DWORDs in which the driver should return information about each [FOURCC](https://learn.microsoft.com/windows-hardware/drivers/) that it supports. The driver should ignore this parameter when it is **NULL**.

## Return value

**DrvGetDirectDrawInfo** returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

The driver's **DrvGetDirectDrawInfo** routine should do the following:

* When *pvmList* and *pdwFourCC* are **NULL**:
  1. Reserve offscreen display memory for DirectDraw use.
  2. Write the number of driver display memory heaps and supported FOURCCs in *pdwNumHeaps* and *pdwNumFourCC*, respectively.
* When *pvmList* and *pdwFourCC* are not **NULL**:
  1. Write the number of driver display memory heaps and supported FOURCCs in *pdwNumHeaps* and *pdwNumFourCC*, respectively.
  2. For each [VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory) structure in the list to which *pvmList* points, fill in the appropriate members to describe a particular chunk of display memory. The list of structures provides DirectDraw with a complete description of the driver's offscreen memory.
* Initialize the members of the [DD_HALINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_halinfo) structure with driver-specific information as follows:
  1. Initialize the appropriate members of the [VIDEOMEMORYINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemoryinfo) structure in *vmiData* to describe the general characteristics of the display's memory.
  2. Initialize the appropriate members of the [DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps) structure in **ddCaps** to describe the capabilities of the hardware.
  3. If the driver implements a [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function, set **GetDriverInfo** to point to it and set **dwFlags** to DDHALINFO_GETDRIVERINFOSET.

## See also

[DD_HALINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_halinfo)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)

[DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw)

[VIDEOMEMORY](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemory)

[VIDEOMEMORYINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-videomemoryinfo)