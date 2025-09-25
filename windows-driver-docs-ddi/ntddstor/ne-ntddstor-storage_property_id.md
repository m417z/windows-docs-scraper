# STORAGE_PROPERTY_ID enumeration

## Description

**STORAGE_PROPERTY_ID** enumerates the possible values for the **PropertyId** member of the **[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)** structure.

## Constants

### `StorageDeviceProperty`

The caller is querying for the device descriptor, **[STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)**.

### `StorageAdapterProperty`

The caller is querying for the adapter descriptor, **[STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_adapter_descriptor)**.

### `StorageDeviceIdProperty`

The caller is querying for the device identifiers provided with the SCSI vital product data pages. Data is returned using the **[STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_id_descriptor)** structure.

### `StorageDeviceUniqueIdProperty`

The caller is querying for the unique device identifiers. Data is returned using the **[STORAGE_DEVICE_UNIQUE_IDENTIFIER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storduid/ns-storduid-_storage_device_unique_identifier)** structure.

### `StorageDeviceWriteCacheProperty`

The caller is querying for the write cache property. Data is returned using the **[STORAGE_WRITE_CACHE_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_write_cache_property)** structure.

### `StorageMiniportProperty`

Reserved for system use.

### `StorageAccessAlignmentProperty`

The caller is querying for the access alignment descriptor, **[STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_access_alignment_descriptor)**.

### `StorageDeviceSeekPenaltyProperty`

The caller is querying for the seek penalty descriptor, **[DEVICE_SEEK_PENALTY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_seek_penalty_descriptor)**.

### `StorageDeviceTrimProperty`

The caller is querying for the trim descriptor, **[DEVICE_TRIM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_trim_descriptor)**.

### `StorageDeviceWriteAggregationProperty`

Reserved for system use.

### `StorageDeviceDeviceTelemetryProperty`

Reserved for system use.

### `StorageDeviceLBProvisioningProperty`

The caller is querying for the logical block provisioning property. Data is returned using the **[DEVICE_LB_PROVISIONING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_lb_provisioning_descriptor)** structure.

### `StorageDevicePowerProperty`

The caller is querying for the device power descriptor. Data is returned using the **[DEVICE_POWER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_power_descriptor)** structure.

### `StorageDeviceCopyOffloadProperty`

The caller is querying for the copy offload parameters property. Data is returned using the **[DEVICE_COPY_OFFLOAD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_copy_offload_descriptor)** structure.

### `StorageDeviceResiliencyProperty`

Reserved for system use.

### `StorageDeviceMediumProductType`

The caller is querying for the medium product type. Data is returned using the **[STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_medium_product_type_descriptor)** structure.

### `StorageAdapterRpmbProperty`

The caller is querying for RPMB support and properties. Data is returned using the **[STORAGE_RPMB_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_rpmb_descriptor)** structure.

### `StorageAdapterCryptoProperty`

Provides information on the storage adapter encryption capabilities. This is currently supported on UFS (Universal Flash Storage) adapters.

### `StorageDeviceTieringProperty`

Reserved for system use.

### `StorageDeviceFaultDomainProperty`

Reserved for system use.

### `StorageDeviceClusportProperty`

Reserved for system use.

### `StorageDeviceDependantDevicesProperty`

Reserved for system use.

### `StorageDeviceIoCapabilityProperty`

The caller is querying for the device I/O capability property. Data is returned using the **[STORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_io_capability_descriptor)** structure.

### `StorageAdapterProtocolSpecificProperty`

The caller is querying for protocol-specific data from the adapter. Data is returned using the **[STORAGE_PROTOCOL_DATA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_data_descriptor)** structure. See the Remarks for more info.

### `StorageDeviceProtocolSpecificProperty`

The caller is querying for protocol-specific data from the device. Data is returned using the **[STORAGE_PROTOCOL_DATA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_data_descriptor)** structure. See the Remarks for more info.

### `StorageAdapterTemperatureProperty`

The caller is querying temperature data from the adapter. Data is returned using the **[STORAGE_TEMPERATURE_DATA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_temperature_data_descriptor)** structure.

### `StorageDeviceTemperatureProperty`

The caller is querying for temperature data from the device. Data is returned using the **[STORAGE_TEMPERATURE_DATA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_temperature_data_descriptor)** structure.

### `StorageAdapterPhysicalTopologyProperty`

The caller is querying for topology information from the adapter. Data is returned using the **[STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_physical_topology_descriptor)** structure.

### `StorageDevicePhysicalTopologyProperty`

The caller is querying for topology information from the device. Data is returned using the **[STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_physical_topology_descriptor)** structure.

### `StorageDeviceAttributesProperty`

Reserved for future use.

### `StorageDeviceManagementStatus`

The caller is querying for health information about the storage device (specifically for the persistent memory stack).

### `StorageAdapterSerialNumberProperty`

The caller is querying for the adapter serial number. Data is returned using the **[STORAGE_ADAPTER_SERIAL_NUMBER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_adapter_serial_number)** structure.

### `StorageDeviceLocationProperty`

Reserved for system use.

### `StorageDeviceNumaProperty`

The caller is querying for the non-uniform memory access (NUMA) node of the storage device.

### `StorageDeviceZonedDeviceProperty`

Reserved for system use.

### `StorageDeviceUnsafeShutdownCount`

Provides the unsafe shutdown count value used to determine if the device data might have been lost during a power loss event (specifically for the persistent memory stack).

### `StorageDeviceEnduranceProperty`

The caller is querying for how many bytes have been read from or written to a solid-state drive (SSD). This property is currently supported only for Non-Volatile Memory Express (NVMe) devices that implement a certain NVMe feature.

### `StorageDeviceLedStateProperty`

The caller is querying for the LED state of the device. Data is returned using the **[STORAGE_DEVICE_LED_STATE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_device_led_state_descriptor)** structure. This property is currently supported only for certain NVMe devices. Supported in Windows Server 2022 and later.

### `StorageDeviceSelfEncryptionProperty`

The caller is querying to determine whether the device supports self encryption. Data is returned using the **[STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_device_self_encryption_property)** structure. Supported in Windows Server 2022 and later.

### `StorageFruIdProperty`

The caller is querying for the ID of a fault replacement unit (FRU). Data is returned using the **[STORAGE_FRU_ID_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_fru_id_descriptor)** structure. Supported in Windows Server 2022 and later.

### `StorageStackProperty`

The caller is querying for the type of the storage stack, such as SCSI, NVMe, and so on. Data is returned using the **[STORAGE_STACK_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_stack_descriptor)** structure.

### `StorageAdapterProtocolSpecificPropertyEx`

The caller is querying for protocol-specific data from the adapter. Data is returned using the **[STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext)** structure. See the Remarks for more info.

### `StorageDeviceProtocolSpecificPropertyEx`

The caller is querying for protocol-specific data from the device. Data is returned using the **[STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext)** structure. See the Remarks for more info.

## Remarks

The **[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)** structure is passed as input to an **[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)** request to retrieve the properties of a storage device or adapter.

The optional output buffer returned from an **IOCTL_STORAGE_QUERY_PROPERTY** control code request can be one of several structures, depending on the value of the **PropertyId** member of the **[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)** structure. If the **QueryType** member of the **STORAGE_PROPERTY_QUERY** is set to **PropertyExistsQuery**, then no structure is returned.

## See also

- **[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)**
- **[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)**
- **[STORAGE_QUERY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_query_type)**