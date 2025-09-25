# IoGetDeviceInterfaces function

## Description

The **IoGetDeviceInterfaces** routine returns a list of device interface instances of a particular device interface class (such as all devices on the system that support a HID interface).

## Parameters

### `InterfaceClassGuid` [in]

Pointer to a class GUID specifying the device interface class. The GUIDs for a class should be in a device-specific header file.

### `PhysicalDeviceObject` [in, optional]

Pointer to an optional PDO that narrows the search to only the device interface instances of the device represented by the PDO.

### `Flags` [in]

Specifies flags that modify the search for device interfaces. Only one flag is currently defined, and is described in the following table.

| Flag | Meaning |
| --- | --- |
| DEVICE_INTERFACE_INCLUDE_NONACTIVE | Return disabled device interface instances in addition to enabled interface instances. |

When searching for a device that supports a particular interface class, the caller requires an enabled interface instance and thus does not set the DEVICE_INTERFACE_INCLUDE_NONACTIVE flag.

A driver typically sets the DEVICE_INTERFACE_INCLUDE_NONACTIVE flag to locate disabled interface instances that the driver must enable. For example, the class installer for the device might have been directed by the INF file to register one or more interface instances for the device. The interface instances would be registered but are not usable until they are enabled by the driver (using [IoSetDeviceInterfaceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdeviceinterfacestate)). To narrow the list of interface instances returned to only those exposed by a given device, a driver can specify a *PhysicalDeviceObject*.

### `SymbolicLinkList` [out]

A pointer to a wide character pointer to which the routine, if successful, writes the base address of a buffer that contains a list of Unicode strings. These strings are symbolic link names that identify the device interface instances that match the search criteria. Each Unicode string in the list is null-terminated; the end of the whole list is marked by an additional null character. The routine allocates the buffer for these strings from paged system memory. The caller is responsible for freeing the buffer (by calling the [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool) routine) when it is no longer needed.

If no device interface instances match the search criteria, this routine returns STATUS_SUCCESS and the string contains a single NULL character.

## Return value

**IoGetDeviceInterfaces** returns STATUS_SUCCESS if the call was successful. Possible error return values include the following.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | Possibly indicates that *PhysicalDeviceObject* was not a valid PDO pointer. |

## Remarks

**IoGetDeviceInterfaces** returns a list of device interface instances that match the search criteria. A kernel-mode component typically calls this routine to get a list of all enabled device interface instances of a particular device interface class. Such a component can get a pointer to the file object and/or the device object for an interface by calling the [IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer) or [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) routine. The device object pointer returned by **IoGetDeviceObjectPointer** points to the top of the device stack for the device and can be used in calls to the [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) routine.

If there is a default interface for the requested device interface class, it is listed first in *SymbolicLinkList*. Default interfaces can be set by user mode, but not by kernel mode.

The format of a symbolic link name is opaque; the caller should not attempt to parse a symbolic link name.

Symbolic links for device interface instances can be used across system boots.

To be notified when additional device interface instances of a particular class are enabled on the system, register for notification of a device class change by calling the [IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification) routine.

Callers of **IoGetDeviceInterfaces** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer)

[IoRegisterDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterdeviceinterface)

[IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)

[IoSetDeviceInterfaceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdeviceinterfacestate)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)