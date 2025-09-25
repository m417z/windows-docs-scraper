# StorPortEtwLogError function

## Description

**StorPortEtwLogError** logs an Event Tracing for Windows (ETW) event for a hardware protocol error.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport's device extension.

### `Address` [in, optional]

The storage unit device address. This parameter is NULL for adapter devices.

### `Id` [in]

A miniport-defined event ID that uniquely identifies the event.

### `Description` [in]

The description text for the error. This parameter is required.

### `DataBufferLength` [in]

Size of *DataBuffer*, in bytes.

### `DataBuffer` [in]

A variable-size buffer that contains driver-specific binary data that is useful in identifying the cause of the error. Drivers must specify the size of this buffer in the *DataBufferLength* parameter.

## Return value

This function returns one of the following status codes.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The event was successfully logged. |
| STOR_STATUS_INVALID_PARAMETER | *Description* or *DataBuffer* are NULL, or *DataBufferLength* is not greater than zero. |
| STOR_STATUS_UNSUCCESSFUL | StorPort was unable to log the ETW event for other reasons, such as ETW logging is not enabled. |

## Remarks

A miniport can call **StorPortEtwLogError** to log an ETW event for a hardware protocol error. Events generated from this function are published to the "Microsoft-Windows-Storage-Storport/Operational" ETW channel.

## See also

[**StorPortEtwEvent2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent2)

[**StorPortEtwEvent4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent4)

[**StorPortEtwEvent8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent8)

[**StorPortEtwLogByteStream**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwlogbytestream)