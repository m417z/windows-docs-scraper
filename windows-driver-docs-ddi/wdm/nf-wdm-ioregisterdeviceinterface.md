# IoRegisterDeviceInterface function

## Description

The **IoRegisterDeviceInterface** routine registers a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/device-interface-classes), if it has not been previously registered, and creates a new instance of the interface class, which a driver can subsequently enable for use by applications or other system components.

## Parameters

### `PhysicalDeviceObject` [in]

A pointer to the PDO for the device.

### `InterfaceClassGuid` [in]

A pointer to the class GUID that identifies the functionality (the device interface class) being registered.

### `ReferenceString` [in, optional]

Optionally points to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string). The string must not contain any path separator characters ("/" or "\\"). Function drivers typically specify **NULL** for this parameter. Filter drivers must specify **NULL**.

Reference strings are only used by a few bus drivers, such as *swenum*, which is a bus driver that uses device interface instances as placeholders for software devices created on demand. When an instance of an interface is opened, the I/O manager passes the instance's reference string to the driver. The string becomes part of the interface instance's name (as an appended path component). The driver can then use the reference string to differentiate between two interface instances of the same class for a single device.

On Microsoft Windows 98/Me systems, the *ReferenceString* value can be no longer than MAX_PATH characters. There is no length limit on Windows 2000 and later versions of Windows.

### `SymbolicLinkName` [out]

A pointer to a Unicode string structure allocated by the caller. If this routine is successful, it initializes the Unicode string and allocates the string buffer containing the kernel-mode path to the symbolic link for an instance of the specified device interface class.

The caller must treat *SymbolicLinkName* as opaque and must not disassemble it.

The caller is responsible for freeing *SymbolicLinkName* with [RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring) when it is no longer needed.

## Return value

**IoRegisterDeviceInterface** returns STATUS_SUCCESS if the call was successful. Possible error return values include the following.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The parameters are invalid. Possibilities include that *PhysicalDeviceObject* does not point to a valid PDO, or that the *ReferenceString* string contains an invalid character. |

## Remarks

**IoRegisterDeviceInterface** registers a device interface class, if it has not been previously registered, and creates a new instance of the interface class. A driver can call this routine several times for a given device to register several interface classes and create instances of the classes. A function or filter driver typically registers device interfaces in its [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine. For example, a fault-tolerant volume driver might register an instance of a fault-tolerant-volume interface and an instance of a volume interface for a particular volume.

If the device interface class has not been registered previously, the I/O manager creates a registry key for it, along with instance-specific persistent storage under the key. Drivers can access this persistent storage using [IoOpenDeviceInterfaceRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendeviceinterfaceregistrykey).

A driver registers an interface instance once and then calls [IoSetDeviceInterfaceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdeviceinterfacestate) to enable and disable the interface.

Registered interfaces persist across operating system reboots. If the specified interface is already registered, the I/O manager passes its name in *SymbolicLinkName* and returns the informational success status STATUS_OBJECT_NAME_EXISTS.

Most drivers use a **NULL** reference string for a device interface instance. If a driver uses a non-**NULL** reference string, it must do additional work, including possibly managing its own namespace and security. A filter driver that exposes a device interface must use a **NULL** *ReferenceString* to avoid conflicts with other drivers in the device stack.

Callers of this routine are not required to remove the registration for a device interface when it is no longer needed. Device interface registrations can be removed from user mode, if necessary.

Callers of **IoRegisterDeviceInterface** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread.

## See also

[IoGetDeviceInterfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceinterfaces)

[IoOpenDeviceInterfaceRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendeviceinterfaceregistrykey)

[IoSetDeviceInterfaceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdeviceinterfacestate)

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)