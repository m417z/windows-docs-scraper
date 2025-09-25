# STORAGE_DEVICE_DESCRIPTOR structure

## Description

The **STORAGE_DEVICE_DESCRIPTOR** structure is used in conjunction with the [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to retrieve the storage device descriptor data for a device.

## Members

### `Version`

Indicates the size of the **STORAGE_DEVICE_DESCRIPTOR** structure. The value of this member will change as members are added to the structure.

### `Size`

Specifies the total size of the descriptor in bytes, including ID strings which are appended to the structure.

### `DeviceType`

Specifies the device type as defined by the Small Computer Systems Interface (SCSI) specification.

### `DeviceTypeModifier`

Specifies the device type modifier, if any, as defined by the SCSI specification. If no device type modifier exists, this member is zero.

### `RemovableMedia`

Indicates when **TRUE** that the device's media (if any) is removable. If the device has no media, this member should be ignored. When **FALSE** the device's media is not removable.

### `CommandQueueing`

Indicates when **TRUE** that the device supports multiple outstanding commands (SCSI tagged queuing or equivalent). When **FALSE**, the device does not support SCSI-tagged queuing or the equivalent. The STORPORT driver is responsible for synchronizing the commands.

### `VendorIdOffset`

Specifies the byte offset from the beginning of the structure to a **NULL**-terminated ASCII string that contains the device's vendor ID. If the device has no vendor ID, this member is zero.

### `ProductIdOffset`

Specifies the byte offset from the beginning of the structure to a **NULL**-terminated ASCII string that contains the device's product ID. If the device has no product ID, this member is zero.

### `ProductRevisionOffset`

Specifies the byte offset from the beginning of the structure to a **NULL**-terminated ASCII string that contains the device's product revision string. If the device has no product revision string, this member is zero.

### `SerialNumberOffset`

Specifies the byte offset from the beginning of the structure to a **NULL**-terminated ASCII string that contains the device's serial number. If the device has no serial number, this member is zero.

### `BusType`

Specifies an enumerator value of type [**STORAGE_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_bus_type) that indicates the type of bus to which the device is connected. This should be used to interpret the raw device properties at the end of this structure (if any).

### `RawPropertiesLength`

Indicates the number of bytes of bus-specific data that have been appended to this descriptor.

### `RawDeviceProperties`

Contains an array of length one that serves as a place holder for the first byte of the bus specific property data.

## Remarks

Applications and storage class drivers issue a device-control request with the I/O control code [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to retrieve this structure, which contains information about a target device. The structure can be retrieved only from an FDO; attempting to retrieve device properties from an adapter causes an error.

An application or driver can determine the required buffer size by casting the retrieved [**STORAGE_DEVICE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor) structure to a [**STORAGE_DESCRIPTOR_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_descriptor_header), which contains only **Version** and **Size**.

## See also

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[**STORAGE_ADAPTER_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_adapter_descriptor)

[**STORAGE_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_bus_type)

[**STORAGE_DESCRIPTOR_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_descriptor_header)

[**STORAGE_DEVICE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)

[**STORAGE_DEVICE_ID_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_id_descriptor)