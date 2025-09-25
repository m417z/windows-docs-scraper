## Description

The **IoReportRootDevice** routine reports a device that cannot be detected by a PnP bus driver to the PnP Manager. **IoReportRootDevice** allows only one device per driver to be created.

## Parameters

### `DriverObject` [in]

Pointer to the driver object of the driver that detected the device.

## Return value

**IoReportRootDevice** returns STATUS_SUCCESS on success, or the appropriate error code on failure.

## Remarks

Drivers for devices that cannot be detected by a PnP bus driver use **IoReportRootDevice** to report their device to the system. Devices that can be detected by a PnP bus driver should be reported in response to an [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) request.

A driver typically calls this routine from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

**IoReportRootDevice** marks the device as a root-enumerated device and this identification is persistent across system boots. The PnP manager "detects" the device on the root-enumerated list and configures it like a PnP device: the PnP manager queries for device information, identifies the appropriate drivers and calls their *AddDevice* routines, and sends all the appropriate PnP IRPs.

The system generates a single Hardware ID string for the device, of the form ROOT\\*Driver* where *Driver* is the driver's service name. A driver can provide additional hardware IDs or compatible IDs by handling the [IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id) request.

A driver writer must provide an INF file that matches any of the specified hardware IDs or compatible IDs. The INF file should specify the original driver that called **IoReportRootDevice** as the driver to load for those IDs. The system uses this information to rebuild the driver stack for the device, for example on restart. Callers of **IoReportRootDevice** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

Drivers should use [IoReportDetectedDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreportdetecteddevice) to report hardware devices that use resources but cannot be detected by a PnP bus driver instead of **IoReportRootDevice**.

## See also

[AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations)

[IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id)

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[IoReportDetectedDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreportdetecteddevice)

[IoReportResourceForDetection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreportresourcefordetection)