# DrvDisableDriver function

## Description

The **DrvDisableDriver** function is used by GDI to notify a driver that it no longer requires the driver and is ready to unload it.

## Remarks

The driver should free all allocated resources and return the device to the state it was in before the driver was loaded.

**DrvDisableDriver** is required for graphics drivers.

## See also

[DrvEnableDriver](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledriver)