# DrvCompletePDEV function

## Description

The **DrvCompletePDEV** function stores the GDI handle of the physical device being created.

## Parameters

### `dhpdev`

Handle to the physical device, which was returned to GDI when it called [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `hdev`

Handle to the physical device that has been installed. This is the GDI handle for the physical device being created. The driver should use this handle when calling GDI functions.

## Remarks

**DrvCompletePDEV** is called by GDI when its installation of the physical device is complete. It also provides the driver with a handle to the PDEV to be used when requesting GDI services for the device. This function is required for graphics drivers; when GDI calls **DrvCompletePDEV**, it cannot fail.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)