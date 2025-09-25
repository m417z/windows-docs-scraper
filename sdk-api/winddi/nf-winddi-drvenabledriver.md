# DrvEnableDriver function

## Description

The **DrvEnableDriver** function is the initial driver entry point exported by the driver DLL. It fills in a [DRVENABLEDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvenabledata) structure with the driver's graphics DDI version number and the calling addresses of all graphics DDI functions supported by the driver.

## Parameters

### `iEngineVersion`

Identifies the version of GDI that is currently running.

### `cj`

Is the size in bytes of the structure pointed to by *pded*. If the structure is larger than expected, extra members should be left unmodified.

### `pded` [in]

Pointer to a [DRVENABLEDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvenabledata) structure. GDI zero-initializes *cj* bytes before the call. The driver fills in its own data.

## Return value

The return value is **TRUE** if the specified driver is enabled. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

**DrvEnableDriver** must be implemented in all graphics drivers. If you use the Windows Driver Kit (WDK) build tools and have set TARGETTYPE to GDI_DRIVER (see [Building a Printer Graphics DLL](https://learn.microsoft.com/windows-hardware/drivers/print/building-a-printer-graphics-dll)), this function must be named **DrvEnableDriver**. This is the only display driver function that must be accessed by name. All other display driver functions are accessed through function pointers; therefore, their names are presented in this documentation as pseudonames.

One-time initializations, such as allocating semaphores, can also be performed by this function. The driver should wait until [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) is called before enabling hardware, such as a display.

When performing version checking using the value provided in *iEngineVersion*, the driver should use the appropriate DDI_DRIVER_VERSION_*Xxx* constant (defined in *winddi.h*) shown in the following table. Drivers should almost never check just for equality since new versions and service pack releases for the operating system will be released in the future. For more information, see [DRVENABLEDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvenabledata).

| Value | Operating System Version |
| --- | --- |
| DDI_DRIVER_VERSION_NT4 | Windows NT 4.0 |
| DDI_DRIVER_VERSION_SP3 | Windows NT 4.0 Service Pack 3 |
| DDI_DRIVER_VERSION_NT5 | Windows 2000 |
| DDI_DRIVER_VERSION_NT5_01 | Windows XP |
| DDI_DRIVER_VERSION_NT5_01_SP1 | Windows XP Service Pack 1 |

## See also

[DRVENABLEDATA](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvenabledata)

[DRVFN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvfn)

[DrvDisableDriver](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisabledriver)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)