# STORAGE_PROTOCOL_NVME_DATA_TYPE enumeration

## Description

Describes the type of NVMe protocol-specific data that's to be queried during an [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) request.

## Constants

### `NVMeDataTypeUnknown:0`

Unknown data type.

### `NVMeDataTypeIdentify`

Identify data type. This can be either Identify Controller data or Identify Namespace data. When this type of data is being queried, the ProtocolDataRequestValue field of [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_specific_data) will have a value of **NVME_IDENTIFY_CNS_CONTROLLER** for adapter or **NVME_IDENTIFY_CNS_SPECIFIC_NAMESPACE** for namespace. If the ProtocolDataRequestValue is **NVME_IDENTIFY_CNS_SPECIFIC_NAMESPACE**, the ProtocolDataRequestSubValue field from the **STORAGE_PROTOCOL_SPECIFIC_DATA** structure will have a value of the namespace ID.

### `NVMeDataTypeLogPage`

Log page data type.

### `NVMeDataTypeFeature`

Feature data type.

## Remarks

When using [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) to retrieve protocol-specific information in the [STORAGE_PROTOCOL_DATA_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_data_descriptor), configure the [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query) structure as follows:
* Allocate a buffer that can contains both a [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query) and a [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure.
* Set the **PropertyID** field to **StorageAdapterProtocolSpecificProperty** or **StorageDeviceProtocolSpecificProperty** for a controller or device/namespace request, respectively.
* Set the **QueryType** field to **PropertyStandardQuery**.
* Fill the [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure with the desired values. The start of the **STORAGE_PROTOCOL_SPECIFIC_DATA** is the **AdditionalParameters** field of [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query).

To specify a type of NVMe protocol-specific information, configure the [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_specific_data) structure as follows:
* Set the **ProtocolType** field to **ProtocolTypeNVMe**.
* Set the **DataType** field to an enumeration value defined by **STORAGE_PROTOCOL_NVME_DATA_TYPE**:
  * Use **NVMeDataTypeIdentify** to get Identify Controller data or Identify Namespace data.
  * Use **NVMeDataTypeLogPage** to get log pages (including SMART/health data).
  * Use **NVMeDataTypeFeature** to get features of the NVMe drive.

## See also

* [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property)
* [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query)
* [STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_protocol_specific_data)