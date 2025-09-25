# STORAGE_PROTOCOL_SPECIFIC_DATA structure

## Description

Describes protocol-specific device data, provided in the input and output buffer of an [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) request.

## Members

### `ProtocolType`

The protocol type. Values for this member are defined in the [STORAGE_PROTOCOL_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_type) enumeration.

### `DataType`

The protocol data type. Data types are defined in the [STORAGE_PROTOCOL_NVME_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_nvme_data_type) and [STORAGE_PROTOCOL_ATA_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_ata_data_type) enumerations.

### `ProtocolDataRequestValue`

The protocol data request value.

### `ProtocolDataRequestSubValue`

The sub value of the protocol data request.

### `ProtocolDataOffset`

The offset of the data buffer that is from the beginning of this structure. The typical value can be sizeof(**STORAGE_PROTOCOL_SPECIFIC_DATA**).

### `ProtocolDataLength`

The length of the protocol data.

### `FixedProtocolReturnData`

The returned data.

### `ProtocolDataRequestSubValue2`

### `ProtocolDataRequestSubValue3`

### `Reserved`

Reserved for future use.

## Remarks

When using [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) to retrieve protocol-specific information in the [STORAGE_PROTOCOL_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_protocol_data_descriptor), configure the [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query) structure as follows:

* Allocate a buffer that can contains both a [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query) and a **STORAGE_PROTOCOL_SPECIFIC_DATA** structure.
* Set the **PropertyID** field to **StorageAdapterProtocolSpecificProperty** or **StorageDeviceProtocolSpecificProperty** for a controller or device/namespace request, respectively.
* Set the **QueryType** field to **PropertyStandardQuery**.
* Fill the **STORAGE_PROTOCOL_SPECIFIC_DATA** structure with the desired values. The start of the **STORAGE_PROTOCOL_SPECIFIC_DATA** is the **AdditionalParameters** field of [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query).

To specify a type of NVMe protocol-specific information, configure the **STORAGE_PROTOCOL_SPECIFIC_DATA** structure as follows:

* Set the **ProtocolType** field to **ProtocolTypeNVMe**.
* Set the **DataType** field to an enumeration value defined by [STORAGE_PROTOCOL_NVME_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_nvme_data_type):
  + Use **NVMeDataTypeIdentify** to get Identify Controller data or Identify Namespace data.
  + Use **NVMeDataTypeLogPage** to get log pages (including SMART/health data).
  + Use **NVMeDataTypeFeature** to get features of the NVMe drive.

To specify a type of ATA protocol-specific information, configure the **STORAGE_PROTOCOL_SPECIFIC_DATA** structure as follows:

* Set the **ProtocolType** field to **ProtocolTypeAta**.
* Set the **DataType** field to an enumeration value defined by [STORAGE_PROTOCOL_ATA_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_ata_data_type):
  + Use **AtaDataTypeIdentify** to identify the ATA drive.
  + Use **AtaDataTypeLogPage** to get log pages from the ATA drive.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query)