## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkddiDisplayMuxReportPresence** function before adapter start to inform the driver that an automatic display switch (ADS) mux has been detected.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `SystemHasMux`

[in] Boolean value that indicates whether the system has an ADS-compatible mux.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

**SystemHasMux** is set to TRUE when an ADS mux device was detected in the system and that mux device meets the ADS requirements. A TRUE value doesn't guarantee that ADS functionality will be available to user at this point in the boot sequence for the following reasons:

* The other GPU involved with the ADS mux might not be started yet.
* The OS has not yet verified all the ADS requirements for this driver.

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).