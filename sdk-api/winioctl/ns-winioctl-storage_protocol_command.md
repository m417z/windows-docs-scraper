# STORAGE_PROTOCOL_COMMAND structure

## Description

This structure is used as an input buffer when using the pass-through mechanism to issue a vendor-specific command to a storage device (via [IOCTL_STORAGE_PROTOCOL_COMMAND](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_protocol_command)).

## Members

### `Version`

The version of this structure. This should be set to **STORAGE_PROTOCOL_STRUCTURE_VERSION**.

### `Length`

The size of this structure. This should be set to sizeof(**STORAGE_PROTOCOL_COMMAND**).

### `ProtocolType`

The protocol type, of type [STORAGE_PROTOCOL_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_protocol_type).

### `Flags`

Flags set for this request. The following are valid flags.

| Flag | Description |
| --- | --- |
| **STORAGE_PROTOCOL_COMMAND_FLAG_ADAPTER_REQUEST** | This flag indicates the request to target an adapter instead of device. |

### `ReturnStatus`

The status of the request made to the storage device. In Windows 10, possible values include:

| Status value | Description |
| --- | --- |
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

The error code for this request. This is optionally set.

### `CommandLength`

The length of the command. A non-zero value must be set by the caller.

### `ErrorInfoLength`

The length of the error buffer. This is optionally set and can be set to 0.

### `DataToDeviceTransferLength`

The size of the buffer that is to be transferred to the device. This is only used with a WRITE request.

### `DataFromDeviceTransferLength`

The size of the buffer this is to be transferred from the device. This is only used with a READ request.

### `TimeOutValue`

How long to wait for the device until timing out. This is set in units of seconds.

### `ErrorInfoOffset`

The offset of the error buffer. This must be pointer-aligned.

### `DataToDeviceBufferOffset`

The offset of the buffer that is to be transferred to the device. This must be pointer-aligned and is only used with a WRITE request.

### `DataFromDeviceBufferOffset`

The offset of the buffer that is to be transferred from the device. This must be pointer-aligned and is only used with a READ request.

### `CommandSpecific`

Command-specific data passed along with the command. This depends on the command from the driver, and is optionally set.

### `Reserved0`

Reserved for future use.

### `FixedProtocolReturnData`

The return data. This is optionally set. Some protocols such as NVMe, may return a small amount of data (DWORD0 from completion queue entry) without the need of a separate device data transfer.

### `Reserved1`

Reserved for future use.

### `Command`

The vendor-specific command that is to be passed-through to the device.

## See also

[IOCTL_STORAGE_PROTOCOL_COMMAND](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_protocol_command)