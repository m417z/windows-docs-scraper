# STORAGE_PROTOCOL_DATA_DESCRIPTOR structure

## Description

This structure is used in conjunction with [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) to return protocol-specific data from a storage device or adapter. .

## Members

### `Version`

The version of this structure.

### `Size`

The total size of the descriptor, including the space for all protocol data.

### `ProtocolSpecificData`

The protocol-specific data, of type [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_protocol_specific_data).

## Remarks

When using [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) to retrieve protocol-specific information in the **STORAGE_PROTOCOL_DATA_DESCRIPTOR**, configure the [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query) structure as follows:

* Allocate a buffer that can contains both a [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query) and a [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure.
* Set the **PropertyID** field to **StorageAdapterProtocolSpecificProperty** or **StorageDeviceProtocolSpecificProperty** for a controller or device/namespace request, respectively.
* Set the **QueryType** field to **PropertyStandardQuery**.
* Fill the [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure with the desired values. The start of the **STORAGE_PROTOCOL_SPECIFIC_DATA** is the **AdditionalParameters** field of [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query).

To specify a type of NVMe protocol-specific information, configure the [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure as follows:

* Set the **ProtocolType** field to **ProtocolTypeNVMe**.
* Set the **DataType** field to an enumeration value defined by [STORAGE_PROTOCOL_NVME_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_nvme_data_type):
  + Use **NVMeDataTypeIdentify** to get Identify Controller data or Identify Namespace data.
  + Use **NVMeDataTypeLogPage** to get log pages (including SMART/health data).
  + Use **NVMeDataTypeFeature** to get features of the NVMe drive.

To specify a type of ATA protocol-specific information, configure the [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure as follows:

* Set the **ProtocolType** field to **ProtocolTypeAta**.
* Set the **DataType** field to an enumeration value defined by [STORAGE_PROTOCOL_ATA_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_ata_data_type):
  + Use **AtaDataTypeIdentify** to identify the ATA drive.
  + Use **AtaDataTypeLogPage** to get log pages from the ATA drive.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query)

[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_protocol_specific_data)