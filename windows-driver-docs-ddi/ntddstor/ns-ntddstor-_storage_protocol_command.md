# STORAGE_PROTOCOL_COMMAND structure

## Description

This structure is used with the [IOCTL_STORAGE_PROTOCOL_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_protocol_command) pass-through mechanism that issues a vendor-specific protocol command to a storage device.

## Members

### `Version`

The version of this structure. Set this to be **STORAGE_PROTOCOL_STRUCTURE_VERSION**.

### `Length`

The size of this structure. Set this to sizeof(**STORAGE_PROTOCOL_COMMAND**).

### `ProtocolType`

The protocol type.

### `Flags`

Flags set for this request. The following are valid flags.

| Flag | Description |
| ---- | ----------- |
| **STORAGE_PROTOCOL_COMMAND_FLAG_ADAPTER_REQUEST** | This flag indicates the request to target an adapter instead of device. |

### `ReturnStatus`

The status of the request made to the storage device. In Windows 10, possible values that can be returned include:

| Status value | Description |
| ------------ | ----------- |
| **STORAGE_PROTOCOL_STATUS_PENDING** | The request is pending. |
| **STORAGE_PROTOCOL_STATUS_SUCCESS** | The request has completed successfully. |
| **STORAGE_PROTOCOL_STATUS_ERROR** | The request has encountered an error. |
| **STORAGE_PROTOCOL_STATUS_INVALID_REQUEST** | The request is not valid. |
| **STORAGE_PROTOCOL_STATUS_NO_DEVICE** | A device is not available to make a request to. |
| **STORAGE_PROTOCOL_STATUS_BUSY** | The device is busy acting on the request. |
| **STORAGE_PROTOCOL_STATUS_DATA_OVERRUN** | The device encountered a data overrun while acting on the request. |
| **STORAGE_PROTOCOL_STATUS_INSUFFICIENT_RESOURCES** | The device cannot complete the request due to insufficient resources. |
| **STORAGE_PROTOCOL_STATUS_NOT_SUPPORTED** | The request is not supported. |

### `ErrorCode`

The bus-specific protocol error code to return for this request. This is optionally set.

### `CommandLength`

The length of the command, in bytes. The caller must set this to a non-zero value.

### `ErrorInfoLength`

The length of the **ErrorCode** buffer, in bytes. This is optionally set and can be set to 0.

### `DataToDeviceTransferLength`

The size of the buffer that is to be transferred to the device.

### `DataFromDeviceTransferLength`

The size of the buffer this is to be transferred from the device.

### `TimeOutValue`

Specifies how long to wait for the device until timing out. This is set in units of seconds.

### `ErrorInfoOffset`

The offset of the **ErrorCode** buffer. This must be pointer-aligned.

### `DataToDeviceBufferOffset`

The offset of the buffer that is to be transferred to the device. This must be pointer-aligned and is only used with a WRITE request.

### `DataFromDeviceBufferOffset`

The offset of the buffer that is to be transferred from the device. This must be pointer-aligned and is only used with a READ request.

### `CommandSpecific`

Additional command-specific data passed along with **Command**. This depends on the command from the driver, and is optionally set.

### `Reserved0`

Reserved for future use.

### `FixedProtocolReturnData`

The return data. This is optionally set. Some protocols like NVMe, may return a small amount of data (DWORD0 from completion queue entry) without the need for a separate device data transfer.

### `FixedProtocolReturnData2`

The return data2. This is optionally set. Some protocols like NVMe, may return a small amount data (DWORD1 from completion queue entry) without the need for separate device data transfer.

### `Reserved1[2]`

Reserved for future use.

### `Command[ANYSIZE_ARRAY]`

The vendor-specific command that is to be passed-through to the device.

## See also

- [IOCTL_STORAGE_PROTOCOL_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_protocol_command)