## Description

The *DdGetDriverInfo* function queries the driver for additional DirectDraw and Direct3D functionality that the driver supports.

## Parameters

### `unnamedParam1`

Points to a [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) structure that contains the information required to perform the query.

## Return value

*DdGetDriverInfo* must return DDHAL_DRIVER_HANDLED.

## Remarks

Drivers must implement *DdGetDriverInfo* to expose driver-supported DirectDraw functionality that is not returnable through [DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw).

The driver's [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo) function returns a pointer to *DdGetDriverInfo* in the **GetDriverInfo** member of the [DD_HALINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_halinfo) structure.

To inform DirectDraw that the **GetDriverInfo** member has been set correctly, the driver must also set the DDHALINFO_GETDRIVERINFOSET bit of the **dwFlags** member in the DD_HALINFO structure.

*DdGetDriverInfo* should determine whether the driver and its hardware support the callbacks or capabilities requested by the specified GUID. For all GUIDs except GUID_D3DParseUnknownCommandCallback, if the driver does provide the requested support, it should set the following members of the [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) structure:

* Set **dwActualSize** to the size in bytes of the callback or capability structure being returned by the driver.
* In the memory that **lpvData** points to, initialize the members of the callback or capability structure that corresponds with the requested feature as follows:
  + Set the **dwSize** member to the size in bytes of the structure.
  + For callbacks, set the function pointers to point to those callbacks implemented by the driver, and set the bits in the **dwFlags** member to indicate what functions the driver supports.
  + For capabilities, set the appropriate members of the capability structure with values supported by the driver/device.
* Return DD_OK in **ddRVal**.

If the driver does not support the feature, it should set **ddRVal** to DDERR_CURRENTLYNOTAVAIL and return.

DirectDraw informs the driver of the expected amount of data in the **dwExpectedSize** member of the [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) structure. The driver must not fill in more data than **dwExpectedSize** bytes.

To avoid problems using *DdGetDriverInfo*:

* Do not implement dependencies based on the order in which *DdGetDriverInfo* is called. For example, avoid hooking driver initialization steps into *DdGetDriverInfo*.
* Do not try to ascertain the DirectDraw version based on the calls to *DdGetDriverInfo*.
* Do not assume anything about the number of times DirectDraw will call the driver, or the number of times DirectDraw will query a given GUID. It is possible that DirectDraw will probe the driver repeatedly with the same GUID. Implementing assumptions about this in the driver hampers its compatibility with future runtimes.

## See also

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)

[DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo)