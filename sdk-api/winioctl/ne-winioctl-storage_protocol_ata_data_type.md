# STORAGE_PROTOCOL_ATA_DATA_TYPE enumeration

## Description

The ATA protocol data type.

## Constants

### `AtaDataTypeUnknown:0`

Unknown data type.

### `AtaDataTypeIdentify`

Identify device data type.

### `AtaDataTypeLogPage`

Log page data type.

## Remarks

When using [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) to retrieve protocol-specific information in the [STORAGE_PROTOCOL_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_data_descriptor), configure the [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query) structure as follows:
* Allocate a buffer that can contains both a [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query) and a [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure.
* Set the **PropertyID** field to **StorageAdapterProtocolSpecificProperty** or **StorageDeviceProtocolSpecificProperty** for a controller or device/namespace request, respectively.
* Set the **QueryType** field to **PropertyStandardQuery**.
* Fill the [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure with the desired values. The start of the **STORAGE_PROTOCOL_SPECIFIC_DATA** is the **AdditionalParameters** field of [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query).

To specify a type of ATA protocol-specific information, configure the [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure as follows:
* Set the **ProtocolType** field to **ProtocolTypeAta**.
* Set the **DataType** field to an enumeration value defined by **STORAGE_PROTOCOL_ATA_DATA_TYPE**:
  * Use **AtaDataTypeIdentify** to identify the ATA drive.
  * Use **AtaDataTypeLogPage** to get log pages from the ATA drive.

## See also

* [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property)
* [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query)
* [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_specific_data)