## Description

**StorPortEtwLogByteStream** logs an Event Tracing for Windows (ETW) event with a general purpose byte stream parameter to the specified channel.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the miniport's device extension.

### `Address` [in, optional]

The storage unit device address. This parameter is NULL for adapter devices.

### `EventChannel` [in]

A [**STORPORT_ETW_EVENT_CHANNEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_event_channel) value that identifies the ETW channel in which to log the event.

### `EventId` [in]

A miniport-defined event ID that uniquely identifies the event.

### `EventDescription` [in]

A short string describing the event. *EventDescription* is required and must be <= STORPORT_ETW_MAX_DESCRIPTION_LENGTH characters, not including the NULL terminator.

### `EventKeywords` [in]

Keyword flags for event categorization. Set to 0 if no keyword is desired. The keywords are a bitwise OR combination of the following.

| Value | Meaning |
| ----- | ------- |
| STORPORT_ETW_EVENT_KEYWORD_IO | The event is related to device IO operations. |
| STORPORT_ETW_EVENT_KEYWORD_PERFORMANCE | The event is performance related. |
| STORPORT_ETW_EVENT_KEYWORD_POWER | The event is related to device power. |
| STORPORT_ETW_EVENT_KEYWORD_ENUMERATION | The event is related to device enumeration. |

### `EventLevel` [in]

The event level. This value can indicate the importance or severity of the event. This is one of the following values.

| Value | Meaning |
| ----- | ------- |
| StorportEtwLevelLogAlways | Log the event unconditionally. The event is logged regardless of any filters set. |
| StorportEtwLevelCritical | Critical level event. |
| StorportEtwLevelError | Error level event. |
| StorportEtwLevelWarning | Warning level event. |
| StorportEtwLevelInformational | Informational event. |
| StorportEtwLevelVerbose | Verbose event information provided. |

### `EventOpcode` [in]

The operational nature of the event. This is one of the following values.

| Value | Meaning |
| ----- | ------- |
| StorportEtwEventOpcodeInfo | General informational event. |
| StorportEtwEventOpcodeStart | Device or unit was starting. |
| StorportEtwEventOpcodeStop | Device or unit was stopping. The event corresponds to the last unpaired start event. |
| StorportEtwEventOpcodeDC_Start | A data collection starting event. These are rundown event types. |
| StorportEtwEventOpcodeDC_Stop | A data collection stopping event. These are rundown event types. |
| StorportEtwEventOpcodeExtension | An extension event. |
| StorportEtwEventOpcodeReply | A reply event. |
| StorportEtwEventOpcodeResume | Device or unit was resuming after suspend. |
| StorportEtwEventOpcodeSuspend | Device or unit is suspended pending completion of another operation. |
| StorportEtwEventOpcodeReceive | Transfer of activity is received from another component. |

### `DataLength` [in]

Length, in bytes, of the byte stream that *Data* points to, where 1 <= *DataLength* <= STORPORT_ETW_MAX_BYTE_STREAM_LENGTH.

### `Data` [in]

Pointer to the miniport's custom ETW byte stream.

## Return value

**StorPortEtwLogByteStream** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The event was successfully logged to the specified ETW channel. |
| STOR_STATUS_INVALID_PARAMETER | A parameter is invalid. For example, *HwDeviceExtension*, *EventDescription*, or *Data* are NULL, *DataLength* is greater than the maximum name length, *EventChannel* is an invalid value. |
| STOR_STATUS_UNSUCCESSFUL | Returned for other internal reasons. |

## Remarks

A miniport can call **StorPortEtwLogByteStream** to log an ETW event to a specific channel with a general purpose byte stream parameter.

**StorPortEtwLogByteStream** is useful when a miniport needs to log context beyond that allowed in [**StorPortEtwEvent2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent2), [**StorPortEtwEvent4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent4), or [**StorPortEtwEvent8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent8). For instance, a miniport can log its internal data structure as a byte stream that can then be used for diagnostic purposes when issues get reported.

## See also

[**StorPortEtwEvent2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent2)

[**StorPortEtwEvent4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent4)

[**StorPortEtwEvent8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent8)

[**StorPortEtwLogError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwlogerror)