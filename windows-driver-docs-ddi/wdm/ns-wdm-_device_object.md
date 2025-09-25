## Description

The **DEVICE_OBJECT** structure is used by the operating system to represent a device object. A device object represents a logical, virtual, or physical device for which a driver handles I/O requests.

## Members

### `Type`

Used by the operating system to indicate that an object is a device object. For device objects, the value of this member is 3. This is a read-only member.

### `Size`

Specifies the size, in bytes, of the device object. This size includes the driver-specified device extension pointed to by the **DeviceExtension** member, but does not include the opaque device object extension pointed to by the **DeviceObjectExtension** member. **Size** is a read-only member.

### `ReferenceCount`

Used by the I/O manager to track the number of open handles for the device that are associated with the device object. This allows the I/O manager to avoid unloading a driver when there are outstanding handles for the driver's device(s). This is a read-only member.

### `DriverObject`

A pointer to the driver object ([DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)), that represents the loaded image of the driver that was input to the [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) and [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routines. This member is set by the I/O manager upon a successful call to [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) or [IoCreateDeviceSecure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibiocreatedevicesecure). This is a read-only member.

### `NextDevice`

A pointer to the next device object, if any, that was created by the same driver. The I/O manager updates this list at each successful call to [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) or [IoCreateDeviceSecure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibiocreatedevicesecure).

A non- Plug and Play (PnP) driver that is being unloaded must traverse ("walk") the list of its device objects and delete them. A PnP driver does not have to walk this list of device objects. Instead, PnP drivers perform their cleanup during the device removal PnP operation ([IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)).

A driver that recreates its device objects dynamically also uses this member. This is a read/write member.

### `AttachedDevice`

A pointer to the attached device object. If there is no attached device object, this member is **NULL**. The device object that is pointed to by the **AttachedDevice** member typically is the device object of a filter driver, which intercepts I/O requests originally targeted to the device represent by the device object. For more information, see the [IoAttachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevice) and [IoAttachDeviceByPointer](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl) topics. This is an opaque member.

### `CurrentIrp`

A pointer to the current IRP if the driver has a [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine whose entry point was set in the driver object and if the driver is currently processing IRP(s). Otherwise, this member is **NULL**. For more information, see the [IoStartPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartpacket) and [IoStartNextPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacket) topics. This is a read-only member.

### `Timer`

A pointer to a timer object. This allows the I/O manager to call a driver-supplied timer routine every second. For more information, see [IoInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializetimer). This is a read/write member.

### `Flags`

Device drivers perform a bitwise **OR** operation with this member in their newly created device objects by using one or more of the following system-defined values.

For more information about how to set the **Flags** member, see [Initializing a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/initializing-a-device-object).

| Value | Meaning |
| ----- | ------- |
| DO_VERIFY_VOLUME (0x00000002) | Removable-media drivers set this flag while they process transfer requests. Such drivers should also check for this flag in the target for a transfer request before they transfer any data. For more information, see the [Supporting Removable Media](https://learn.microsoft.com/windows-hardware/drivers/kernel/supporting-removable-media) topic. |
| DO_BUFFERED_IO (0x00000004) | Specifies the type of buffering that is used by the I/O manager for I/O requests that are sent to the device stack. Higher-level drivers OR this member with the same value as the next-lower driver in the stack, except possibly for highest-level drivers. |
| DO_EXCLUSIVE (0x00000008) | Indicates that the driver services an exclusive device, such as a video, serial, parallel, or sound device. WDM drivers must not set this flag. For more information, see the [Specifying Exclusive Access to Device Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-exclusive-access-to-device-objects) topic. |
| DO_DIRECT_IO (0x00000010) | See DO_BUFFERED_IO. |
| DO_MAP_IO_BUFFER (0x00000020) | This flag is no longer used. Drivers should not set this flag. |
| DO_DEVICE_INITIALIZING (0x00000080) | The I/O manager sets this flag when it creates the device object. A device function driver or filter driver clears the flag in its [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine, after it: (1) Attaches the device object to the device stack. (2) Establishes the device power state. (3) Performs a bitwise OR operation on the member with one of the power flags (if it is necessary). The Plug and Play (PnP) manager checks that the flag is clear after the [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine returns. |
| DO_SHUTDOWN_REGISTERED (0x00000800) | Used by the I/O manager to indicate that a driver has registered the device object for shutdown notifications. This flag should not be used by drivers. |
| DO_BUS_ENUMERATED_DEVICE (0x00001000) | The operating system sets this flag in each physical device object (PDO). Drivers must not modify this flag. |
| DO_POWER_PAGABLE (0x00002000) | Pageable drivers that are compatible with Microsoft Windows 2000 and later versions of Windows, are not part of the paging path, and do not require inrush current must set this flag. The system calls such drivers at IRQL = PASSIVE_LEVEL. Drivers cannot set both this flag and DO_POWER_INRUSH. All drivers for WDM, Microsoft Windows 98, and Windows Millennium Edition must set DO_POWER_PAGABLE. |
| DO_POWER_INRUSH (0x00004000) | Drivers of devices that require inrush current when the device is turned on must set this flag. A driver cannot set both this flag and DO_POWER_PAGABLE. |
| DO_DEVICE_TO_BE_RESET (0x04000000) | The I/O manager sets this flag as a signal for the bus driver to reset the device. Other drivers should not use this flag. |
| DO_DAX_VOLUME (0x10000000) | Indicates that a volume is a DAX volume. |

### `Characteristics`

Specifies one or more system-defined constants, combined with a bitwise OR operation, that provide additional information about the driver's device. These constants include the following:

| Value | Meaning |
| ----- | ------- |
| FILE_AUTOGENERATED_DEVICE_NAME | Directs the I/O manager to generate a name for the device, instead of the caller specifying a *DeviceName* when it calls this routine. The I/O manager makes sure that the name is unique. This characteristic is typically specified by a PnP bus driver to generate a name for a physical device object (PDO) for a child device on the same bus. |
| FILE_CHARACTERISTIC_PNP_DEVICE | Indicates that the device object is part of a Plug and Play (PnP) stack. This characteristic is required if a bus driver (or bus filter driver) registers WMI support for a device object that has not yet received the [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request. FILE_CHARACTERISTIC_PNP_DEVICE is also required if a function or filter driver registers for WMI *before* attaching to its device stack. |
| FILE_CHARACTERISTIC_TS_DEVICE | Indicates that the device object is part of a Terminal Services device stack. Drivers should not set this characteristic. |
| FILE_CHARACTERISTIC_WEBDAV_DEVICE | Indicates that a Web-based Distributed Authoring and Versioning (WebDAV) file system is mounted on the device. Drivers should not set this characteristic. |
| FILE_DEVICE_IS_MOUNTED | Indicates that a file system is mounted on the device. Drivers should not set this characteristic. |
| FILE_DEVICE_SECURE_OPEN | Directs the I/O manager to apply the security descriptor of the device object to relative opens and trailing file name opens for the device. For more information, see the [Controlling Device Namespace Access](https://learn.microsoft.com/windows-hardware/drivers/kernel/controlling-device-namespace-access) topic. |
| FILE_FLOPPY_DISKETTE | Indicates that the device is a floppy disk device. |
| FILE_READ_ONLY_DEVICE | Indicates that the device cannot be written to. |
| FILE_REMOTE_DEVICE | Indicates that the device is remote. |
| FILE_REMOVABLE_MEDIA | Indicates that the storage device supports removable media. Notice that this characteristic indicates removable *media*, not a removable *device*. For example, drivers for JAZ drive devices should specify this characteristic, but drivers for PCMCIA flash disks should not. |
| FILE_VIRTUAL_VOLUME | Indicates that the volume is virtual. Drivers should not set this characteristic. |
| FILE_WRITE_ONCE_MEDIA | Indicates that the device supports write-once media. Drivers do not set this member directly. For more information about how to set device characteristics, see the [Specifying Device Characteristics](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-characteristics) topic. |
| FILE_CHARACTERISTIC_CSV | Indicates that the device is a Cluster Shared Volume (CSV). |
| FILE_DEVICE_ALLOW_APPCONTAINER_TRAVERSAL | The IO Manager normally performs a full security check for traverse access on every file open when the client is an app container. Setting of this flag bypasses this enforced traverse access check if the client token already has traverse privileges. |
| FILE_PORTABLE_DEVICE | Indicates that the underlying stack considers the device portable. This is used by the storage stack and means that the device is not in the local machine container and is not on a fixed bus type. |

### `Vpb`

A pointer to the volume parameter block (VPB) that is associated with the device object. For file system drivers, the VPB can provide a connection to any unnamed logical device object that represents an instance of a mounted volume. This is an opaque member.

### `DeviceExtension`

A pointer to the device extension. The structure and contents of the device extension are driver-defined. The size is driver-determined, specified in the driver's call to [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) or [IoCreateDeviceSecure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibiocreatedevicesecure). For more information about device extensions, see [Device Extensions](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-extensions). This is a read-only member. However, the object that the member points to can be modified by the driver.

### `DeviceType`

Set by [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) and [IoCreateDeviceSecure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibiocreatedevicesecure) using the value that is specified for that routine's *DeviceType* parameter. For more information, see the [Specifying Device Types](https://learn.microsoft.com/windows-hardware/drivers/kernel/specifying-device-types) topic.

### `StackSize`

Specifies the minimum number of stack locations in IRPs to be sent to this driver. [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) and [IoCreateDeviceSecure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibiocreatedevicesecure) set this member to 1 in newly created device objects; lowest-level drivers can therefore ignore this member. The I/O manager automatically sets the **StackSize** member in a higher-level driver's device object to the appropriate value if the driver calls [IoAttachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevice) or [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack). Only a higher-level driver that chains itself over another driver with **IoGetDeviceObjectPointer** must explicitly set the value of **StackSize** in its own device object(s) to 1 + the **StackSize** value of the next-lower driver's device object.

### `Queue`

Used internally by the I/O manager to queue the device object when it is required. This is an opaque member.

### `Queue.ListEntry`

A [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure that contains forward and backward pointers for a doubly linked list.

### `Queue.Wcb`

Device context information used by I/O manager.

### `AlignmentRequirement`

Specifies the device's address alignment requirement for data transfers. The value must be one of the FILE_*XXX*_ALIGNMENT values that are defined in Wdm.h. For more information, see the [Initializing a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/initializing-a-device-object), [GetDmaAlignment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_alignment), and [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) topics.

### `DeviceQueue`

The device queue object for the device object. The device queue object contains any IRPs that are waiting to be processed by the driver that is associated with the device object. For more information, see the [Driver-Managed IRP Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/driver-managed-irp-queues) topic. This is an opaque member.

### `Dpc`

The deferred procedure call (DPC) object for the device object. For more information, see the [Introduction to DPC Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-dpc-objects) topic. This is an opaque member.

### `ActiveThreadCount`

Reserved for future use. This is an opaque member.

### `SecurityDescriptor`

Specifies a security descriptor ([SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)) for the device object when the device object is created. If this member is **NULL**, the device object receives default security settings. This is a read-only member, although the member can be modified through the [ZwSetSecurityObject](https://learn.microsoft.com/previous-versions/ff567106(v=vs.85)) function.

### `DeviceLock`

A synchronization event object that is allocated by the I/O manager. The I/O manager obtains his event object before it dispatches a mount or mount-verify request to a file-system driver. This is an opaque member.

### `SectorSize`

If the device object does not represent a volume, this member is set to zero. If the device object represents a volume, this member specifies the volume's sector size, in bytes. The I/O manager uses this member to make sure that all read operations, write operations, and set file position operations that are issued are aligned correctly when intermediate buffering is disabled. A default system bytes-per-sector value is used when the device object is created, however, file system drivers; and more rarely, legacy and minifilter drivers, can update this value that is based on the geometry of the underlying volume hardware when a mount occurs. Other drivers should not modify this member.

### `Spare1`

Reserved for system use. This is an opaque member.

### `DeviceObjectExtension`

A pointer to a device object extension that is used by the I/O manager and PnP manager to store information about the state of the device. This is an opaque member.

### `Reserved`

Reserved for system use. This is an opaque member.

## Remarks

The operating system represents devices by device objects. For more information, see the [Device Objects and Device Stacks](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-objects-and-device-stacks) topic.

Drivers create device objects by using the [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) and [IoCreateDeviceSecure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdmsec/nf-wdmsec-wdmlibiocreatedevicesecure) routines. For more information about how to create device objects, see [Creating a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-device-object).

A device object is partially opaque. Drivers do not set members of the device object directly, unless otherwise documented. For more information about the members that drivers can modify directly, see [Initializing a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/initializing-a-device-object). For information about other device object properties, see [Properties of Device Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/properties-of-device-objects).

Opaque members within a device object must be considered inaccessible. Drivers that have dependencies on object member locations or access to opaque members might not remain portable and interoperable with other drivers over time.

The system-supplied video port driver sets up the fields of the device objects that it creates on behalf of [video miniport drivers](https://learn.microsoft.com/windows-hardware/drivers/display/video-miniport-drivers-in-the-windows-2000-display-driver-model).

The system-supplied SCSI port driver sets up the fields of the device objects that it creates on behalf of [SCSI miniport drivers](https://learn.microsoft.com/windows-hardware/drivers/storage/scsi-miniport-drivers).

The system-supplied NDIS library sets up the fields of the device objects that it creates on behalf of [NDIS miniport drivers](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff557068(v=vs.85)).

## See also

- [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)
- [IoAttachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevice)
- [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack)
- [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)
- [IoDeleteDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletedevice)
- [IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer)