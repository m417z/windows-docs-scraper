# IoReportDetectedDevice function

## Description

The **IoReportDetectedDevice** routine reports a non-PnP device to the PnP manager.

## Parameters

### `DriverObject` [in]

Pointer to the driver object of the driver that detected the device.

### `LegacyBusType` [in]

Specifies the type of bus on which the device resides. The PnP manager uses this information to match the reported device to its PnP-enumerated instance, if one exists.

The interface types, such as **PCIBus**, are defined in Wdm.h. If a driver does not know the *LegacyBusType* for the device, the driver supplies the value **InterfaceTypeUndefined** for this parameter.

### `BusNumber` [in]

Specifies the bus number for the device. The PnP manager uses this information to match the reported device to its PnP-enumerated instance, if one exists.

The bus number distinguishes the bus on which the device resides from other buses of the same type on the computer. The bus-numbering scheme is bus-specific. If a driver does not know the *BusNumber* for the device, the driver supplies the value -1 for this parameter.

### `SlotNumber` [in]

Specifies the logical slot number of the device. The PnP manager uses this information to match the reported device to its PnP-enumerated instance, if one exists.

If a driver does not know the *SlotNumber* for the device, the driver supplies the value -1 for this parameter.

### `ResourceList` [in, optional]

Pointer to the resource list the driver used to detect the device. Resources in this list are in raw, untranslated form.

### `ResourceRequirements` [in, optional]

Optionally points to a resource requirements list for the detected device. **NULL** if the caller does not have this information for the device.

### `ResourceAssigned` [in]

Specifies whether the device's resources have already been reported to the PnP manager. If *ResourceAssigned* is **TRUE**, the resources have already been reported, possibly with [IoReportResourceForDetection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreportresourcefordetection), and the PnP manager will not attempt to claim them on behalf of the device. If **TRUE**, the PnP manager will also not claim resources when the device is root-enumerated on subsequent boots.

### `DeviceObject` [in, out]

Optionally points to a PDO for the detected device.

**NULL** if the caller does not have a PDO for the device, which is typically the case. If *DeviceObject* is **NULL**, the PnP manager creates a PDO for the device and returns a pointer to the caller.

If the caller supplies a PDO, the PnP manager does not create a new PDO. On a given call to this routine the *DeviceObject* parameter is either an IN or an OUT parameter, but not both.

## Return value

**IoReportDetectedDevice** returns STATUS_SUCCESS on success, or the appropriate error code on failure.

## Remarks

Drivers for legacy devices use **IoReportDetectedDevice** to report their devices to the system. A driver should only call **IoReportDetectedDevice** to report a legacy, non-PnP device. PnP devices should be reported in response to an [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) request.

Drivers only need to call **IoReportDetectedDevice** the first time they are loaded because the PnP manager caches the reported information. Drivers that use this routine should store a flag in the registry to indicate whether they have already done device detection.

A driver typically calls this routine from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. A few drivers, like certain NDIS or EISA drivers, might call this routine from an [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

On successful completion of **IoReportDetectedDevice**, the caller should attach an FDO to the PDO returned at *DeviceObject*. Once the caller attaches its FDO, the caller is the function driver for the device, at least temporarily. There are no filter drivers. The PnP manager owns the PDO.

The PnP manager considers the device to be started and therefore does not call the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine and does not send an [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request. The driver must be prepared to handle all other PnP IRPs, however.

**IoReportDetectedDevice** marks the device as a root-enumerated device and this identification is persistent across system boots. During subsequent system boots the PnP manager "detects" the device on the root-enumerated list and configures it like a PnP device: the PnP manager queries for device information, identifies the appropriate drivers and calls their *AddDevice* routines, and sends all the appropriate PnP IRPs.

The system generates two compatible ID strings for the device, of the form DETECTED*Interface*\\*Driver* and DETECTED\\*Driver*. *Interface* is the string name of the [INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_interface_type) of the first bus specified in the *ResourceList* parameter. *Interface* is set to "Internal" if no bus is specified. *Driver* is the driver's service name. A driver can provide additional hardware IDs or compatible IDs by handling the [IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id) request.

A driver writer must provide an INF file that matches any of the specified hardware IDs or compatible IDs. The INF file should specify the original driver that called **IoReportDetectedDevice** as the driver to load for those IDs. The system uses this information to rebuild the driver stack for the device, for example on restart. Callers of **IoReportDetectedDevice** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations)

[IoReportResourceForDetection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreportresourcefordetection)