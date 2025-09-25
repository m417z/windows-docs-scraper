# STORAGE_PROTOCOL_NVME_DATA_TYPE enumeration

## Description

Describes the type of NVMe protocol-specific data that is to be queried during an **[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)** request.

## Constants

### `NVMeDataTypeUnknown`

Unknown data type.

### `NVMeDataTypeIdentify`

Get Identify data, which can be either Identify Controller data or Identify Namespace data.

When this type of data is being queried, fields in the **[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)** structure should have the following values:

- **ProtocolDataRequestValue** will be **NVME_IDENTIFY_CNS_CONTROLLER** for adapter or **NVME_IDENTIFY_CNS_SPECIFIC_NAMESPACE** for namespace.
- If the **ProtocolDataRequestValue** is **NVME_IDENTIFY_CNS_SPECIFIC_NAMESPACE**, the **ProtocolDataRequestSubValue** field specifies the namespace ID. (Note that **NVME_IDENTIFY_CNS_ACTIVE_NAMESPACES** is currently not supported.)

### `NVMeDataTypeLogPage`

Get an NVMe log page.

When this type of data is being queried, fields in the **[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)** structure should have the following values:

- **ProtocolDataRequestValue** is the identifier of the log page to retrieve.
- **ProtocolDataRequestSubValue** is the lower 32-bit value of the offset within a log page from which to start returning data.
- **ProtocolDataRequestSubValue2** is the upper 32-bit value of the offset within a log page from which to start returning data.
- **ProtocolDataRequestSubValue3** is the log-specific identifier that is required for a particular log page.
- **ProtocolDataRequestSubValue4** is a **[STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_data_subvalue_get_log_page)** structure that allows additional information to be specified when getting the log page.

### `NVMeDataTypeFeature`

Retrieved by command - GET FEATURES or SET FEATURES

Corresponding values in **[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)** (get) or **[STORAGE_PROTOCOL_SPECIFIC_DATA_EXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext)** (set):

- **ProtocolDataRequestValue** - Defined in NVME_CDW10_GET_FEATURES / NVME_CDW10_SET_FEATURES
- **ProtocolDataRequestSubValue** - Defined in NVME_CDW11_FEATURES
- **ProtocolDataRequestSubValue2** - Defined in NVME_CDW12_FEATURES
- **ProtocolDataRequestSubValue3** - Defined in NVME_CDW13_FEATURES
- **ProtocolDataRequestSubValue4** - Defined in NVME_CDW14_FEATURES
- **ProtocolDataRequestSubValue5** - Defined in NVME_CDW15_FEATURES

### `NVMeDataTypeLogPageEx`

Retrieved by command - GET LOG PAGE

When this type of data is being queried, fields in the **[STORAGE_PROTOCOL_SPECIFIC_DATA_EXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext)** structure should have the following values:

- **ProtocolDataValue** - Defined in NVME_CDW10_GET_LOG_PAGE
- **ProtocolDataSubValue** - Defined in NVME_CDW11_GET_LOG_PAGE
- **ProtocolDataSubValue2** - Defined in NVME_CDW12_GET_LOG_PAGE
- **ProtocolDataSubValue3** - Defined in NVME_CDW13_GET_LOG_PAGE
- **ProtocolDataSubValue4** - Defined in NVME_CDW14_GET_LOG_PAGE
- **ProtocolDataSubValue5** - Defined in NVME_CDW15_GET_LOG_PAGE (not used currently)
- **ProtocolDataSubValue6** - Namespace ID

### `NVMeDataTypeFeatureEx`

Retrieved by command - GET FEATURES or SET FEATURES

When this type of data is being queried, fields in the **[STORAGE_PROTOCOL_SPECIFIC_DATA_EXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_specific_data_ext)** structure should have the following values:

- **ProtocolDataValue** - Defined in NVME_CDW10_GET_FEATURES / NVME_CDW10_SET_FEATURES
- **ProtocolDataSubValue** - Defined in NVME_CDW11_FEATURES
- **ProtocolDataSubValue2** - Defined in NVME_CDW12_FEATURES
- **ProtocolDataSubValue3** - Defined in NVME_CDW13_FEATURES
- **ProtocolDataSubValue4** - Defined in NVME_CDW14_FEATURES
- **ProtocolDataSubValue5** - Defined in NVME_CDW15_FEATURES
- **ProtocolDataSubValue6** - Namespace ID

## Remarks

When using **[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)** to retrieve protocol-specific information in the **[STORAGE_PROTOCOL_DATA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_data_descriptor)**, configure the **[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)** structure as follows:

- Allocate a buffer that can contains both a **[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)** and a **[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)** structure.

- Set the **PropertyID** field to **StorageAdapterProtocolSpecificProperty** or **StorageDeviceProtocolSpecificProperty** for a controller or device/namespace request, respectively.

- Set the **QueryType** field to **PropertyStandardQuery**.

- Fill the **[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)** structure with the desired values. The start of the **STORAGE_PROTOCOL_SPECIFIC_DATA** is the **AdditionalParameters** field of **[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)**.

To specify a type of NVMe protocol-specific information, configure the **[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)** structure as follows:

- Set the **ProtocolType** field to **ProtocolTypeNVMe**.

- Set the **DataType** field to an enumeration value defined by **STORAGE_PROTOCOL_NVME_DATA_TYPE**:
  - Use **NVMeDataTypeIdentify** to get Identify Controller data or Identify Namespace data.
  - Use **NVMeDataTypeLogPage** to get log pages (including SMART/health data).
  - Use **NVMeDataTypeFeature** to get features of the NVMe drive.
  - Use **NVMeDataTypeLogPageEx** to get log pages (including SMART/health data) using extended format.
  - Use **NVMeDataTypeFeatureEx** to get features of the NVMe drive using extended format.

## See also

- **[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)**
- **[STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)**
- **[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)**
- **[STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_protocol_data_subvalue_get_log_page)**
- **[STORAGE_PROTOCOL_SPECIFIC_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_specific_data)**