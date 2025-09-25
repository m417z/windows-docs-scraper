# STORAGE_PROPERTY_ID enumeration

## Description

Enumerates the possible values of the **PropertyId** member of the [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query) structure passed as input to the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) request to retrieve the properties of a storage device or adapter.

## Constants

### `StorageDeviceProperty:0`

Indicates that the caller is querying for the device descriptor, [STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_device_descriptor).

### `StorageAdapterProperty`

Indicates that the caller is querying for the adapter descriptor, [STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_adapter_descriptor).

### `StorageDeviceIdProperty`

Indicates that the caller is querying for the device identifiers provided with the SCSI vital product data pages. Data is returned using the [STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_device_id_descriptor) structure.

### `StorageDeviceUniqueIdProperty`

**Intended for driver usage.** Indicates that the caller is querying for the unique device identifiers. Data is returned using the **STORAGE_DEVICE_UNIQUE_IDENTIFIER** structure (see the storduid.h header in the DDK).

**Windows Server 2003 and Windows XP:** This value is not supported before Windows Vista and Windows Server 2008.

### `StorageDeviceWriteCacheProperty`

Indicates that the caller is querying for the write cache property. Data is returned using the [STORAGE_WRITE_CACHE_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_write_cache_property) structure.

**Windows Server 2003 and Windows XP:** This value is not supported before Windows Vista and Windows Server 2008.

### `StorageMiniportProperty`

Reserved for system use.

### `StorageAccessAlignmentProperty`

Indicates that the caller is querying for the access alignment descriptor, [STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_access_alignment_descriptor).

**Windows Server 2003 and Windows XP:** This value is not supported before Windows Vista and Windows Server 2008.

### `StorageDeviceSeekPenaltyProperty`

Indicates that the caller is querying for the seek penalty descriptor, [DEVICE_SEEK_PENALTY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_seek_penalty_descriptor).

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 7 and Windows Server 2008 R2.

### `StorageDeviceTrimProperty`

Indicates that the caller is querying for the trim descriptor, [DEVICE_TRIM_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_trim_descriptor).

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 7 and Windows Server 2008 R2.

### `StorageDeviceWriteAggregationProperty`

Reserved for system use.

### `StorageDeviceDeviceTelemetryProperty`

Reserved for system use.

### `StorageDeviceLBProvisioningProperty`

Indicates that the caller is querying for the logical block provisioning property. Data is returned using the [DEVICE_LB_PROVISIONING_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_lb_provisioning_descriptor) structure.

**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012.

### `StorageDevicePowerProperty`

Indicates that the caller is querying for the device power descriptor. Data is returned using the [DEVICE_POWER_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_power_descriptor) structure.

**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012.

### `StorageDeviceCopyOffloadProperty`

Indicates that the caller is querying for the copy offload parameters property. Data is returned using the [DEVICE_COPY_OFFLOAD_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_copy_offload_descriptor) structure.

**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported before Windows 8 and Windows Server 2012.

### `StorageDeviceResiliencyProperty`

Reserved for system use.

### `StorageDeviceMediumProductType`

Indicates that the caller is querying for the medium product type. Data is returned using the [STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_medium_product_type_descriptor) structure.

### `StorageAdapterRpmbProperty`

Indicates that the caller is querying for RPMB support and properties. Data is returned using the [STORAGE_RPMB_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_rpmb_descriptor) structure.

### `StorageAdapterCryptoProperty`

Provides info on the storage adapter encryption capabilities. This is currently supported on UFS (Universal Flash Storage) adapters.

### `StorageDeviceIoCapabilityProperty:48`

Indicates that the caller is querying for the device I/O capability property. Data is returned using the [DEVICE_IO_CAPABILITY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_device_io_capability_descriptor) structure.

### `StorageAdapterProtocolSpecificProperty`

Indicates that the caller is querying for protocol-specific data from the adapter. Data is returned using the [STORAGE_PROTOCOL_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_data_descriptor) structure. See the remarks for more info.

### `StorageDeviceProtocolSpecificProperty`

Indicates that the caller is querying for protocol-specific data from the device. Data is returned using the [STORAGE_PROTOCOL_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_data_descriptor) structure. See the remarks for more info.

### `StorageAdapterTemperatureProperty`

Indicates that the caller is querying temperature data from the adapter. Data is returned using the [STORAGE_TEMPERATURE_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_temperature_data_descriptor) structure.

### `StorageDeviceTemperatureProperty`

Indicates that the caller is querying for temperature data from the device. Data is returned using the [STORAGE_TEMPERATURE_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_temperature_data_descriptor) structure.

### `StorageAdapterPhysicalTopologyProperty`

Indicates that the caller is querying for topology information from the adapter. Data is returned using the [STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_physical_topology_descriptor) structure.

### `StorageDevicePhysicalTopologyProperty`

Indicates that the caller is querying for topology information from the device. Data is returned using the [STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_physical_topology_descriptor) structure.

### `StorageDeviceAttributesProperty`

Reserved for future use.

### `StorageDeviceManagementStatus`

Provides health information about the storage device (specifically for the persistent memory stack).

### `StorageAdapterSerialNumberProperty`

Indicates that the caller is querying for the adapter serial number. Data is returned using the [STORAGE_ADAPTER_SERIAL_NUMBER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_adapter_serial_number) structure.

### `StorageDeviceLocationProperty`

Reserved for system use.

### `StorageDeviceNumaProperty`

Provides the non-uniform memory access (NUMA) node of the storage device.

### `StorageDeviceZonedDeviceProperty`

Reserved for system use.

### `StorageDeviceUnsafeShutdownCount`

Provides the unsafe shutdown count value used to determine if the device data might have been lost during a power loss event (specifically for the persistent memory stack).

### `StorageDeviceEnduranceProperty`

Provides info on how many bytes have been read/write from a solid-state drive (SSD). This property is supported only for Non-Volatile Memory Express (NVMe) devices that implement a certain NVMe feature.

### `StorageDeviceLedStateProperty`

Provides info on the state of the LED associated with a storage device. This is a server-oriented feature.

### `StorageDeviceSelfEncryptionProperty:64`

Reserved for system use.

### `StorageFruIdProperty`

Provides identification info for a storage device that can be physically replaced with a Field Replacement Unit (FRU).

## Remarks

The optional output buffer returned through the *lpOutBuffer* parameter of the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code request can be one of several structures depending on the value of the **PropertyId** member of the [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query) structure pointed to by the *lpInBuffer* parameter. If the **QueryType** member of the **STORAGE_PROPERTY_QUERY** is set to **PropertyExistsQuery**, then no structure is returned.

## See also

* [Disk Management Enumeration Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-enumeration-types)
* [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property)
* [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query)
* [STORAGE_QUERY_TYPE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-storage_query_type)