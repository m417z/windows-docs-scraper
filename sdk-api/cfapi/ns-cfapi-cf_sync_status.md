# CF_SYNC_STATUS structure

## Description

Used in a [CF_OPERATION_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_info) structure to describe the status of a specified sync root.

## Members

### `StructSize`

The size, in bytes, of the sync status structure, including the actual description string.

### `Code`

The use of this parameter is completely up to the sync provider that supports this rich sync status construct.

For a particular sync provider, it is expected that there is a 1:1 mapping between the code and the description string.

It is recommended that you use the highest bit order to describe the type of error code: `1` for an error-level code, and `0` for an information-level code.

>[!NOTE]
>*Code* is opaque to the platform, and is used only for tracking purposes.

### `DescriptionOffset`

The offset of the description string relative to the start of **CF_SYNC_STATUS**. It points to a localized null-terminated wide string that is expected to contain more meaningful and actionable information about the file in question. Sync providers are expected to balance the requirement of providing more actionable information and maintaining an as small as possible memory footprint.

### `DescriptionLength`

The size of the description string, in bytes, that includes the null terminator.

### `DeviceIdOffset`

The offset of a device id blob relative to the start of **CF_SYNC_STATUS**. The device id blob is optional and opaque to the platform. The blob is expected to be unique on a per device basis. If provided, the blob will be collected as part of the platform telemetry to help diagnose technical issues.

### `DeviceIdLength`

The size of the device id blob, in bytes.

## Remarks

If a null pointer is set in the *SyncStatus* field of a [CF_OPERATION_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_info) structure, the platform will clear the previously set sync status, if there is one.

## See also

[CF_OPERATION_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_info)