## Description

A miniport calls **StorPortEtwChannelEvent2** to log an ETW event with two general-purpose ETW parameters to a specified channel.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the hardware device extension for the host bus adapter (HBA).

### `Address`

[in/optional] The storage unit device address. This parameter is NULL for adapter devices.

### `EventChannel`

[in] A [**STORPORT_ETW_EVENT_CHANNEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_event_channel) value that specifies the Storport channel on which to log the event.

### `EventId`

[in] A miniport-defined identifier to uniquely identify the type of event.

### `EventDescription`

[in] Required string that describes the event. The maximum size of the string is **STORPORT_ETW_MAX_DESCRIPTION_LENGTH** characters, not including the null terminator.

### `EventKeywords`

[in] Keyword flags for event categorization. Set to 0 if no keyword is desired. The keywords are a bitwise OR combination of the following.

| Value | Meaning |
| ----- | ------- |
| STORPORT_ETW_EVENT_KEYWORD_IO | The event is related to device IO operations. |
| STORPORT_ETW_EVENT_KEYWORD_PERFORMANCE | The event is performance related. |
| STORPORT_ETW_EVENT_KEYWORD_POWER | The event is related to device power. |
| STORPORT_ETW_EVENT_KEYWORD_ENUMERATION | The event is related to device enumeration. |

### `EventLevel`

[in] A [**STORPORT_ETW_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_level) value that specifies the importance or severity of the event.

### `EventOpcode`

[in] A [**STORPORT_ETW_EVENT_OPCODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_event_opcode) value that specifies the operational nature of the event.

### `Srb`

[in] A pointer to the SRB associated with the logged event. If this parameter contains a valid SRB, this SRB pointer and the associated SRB pointer are logged.

### `Parameter1Name`

[in] A description of the meaning of **Parameter1Value**. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter1Value`

[in] The value for parameter 1.

### `Parameter2Name`

[in] A description of the meaning of **Parameter2Value**. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter2Value`

[in] The value for parameter 2.

## Return value

**StorPortEtwChannelEvent2** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The event was successfully logged. |
| STOR_STATUS_NOT_IMPLEMENTED | Tracing is not enabled for storage events. |
| STOR_STATUS_INVALID_PARAMETER | One of the parameters is invalid. For example, **HwDeviceExtension** or **EventDescription** are NULL, **EventDescription** is greater than the maximum name length, or an ETW parameter name is greater than the maximum name length. |

## Remarks

A miniport can call **StorPortEtwChannelEvent2** to log two general-purpose ETW parameters. The ETW parameters are expressed as two name-value pairs. If a parameter is not named (Parameter*X*Name = NULL), the routine will set the corresponding parameter value to 0.

Events generated from StorPort miniport drivers are logged in the channel specified by **EventChannel**.

## See also

[**StorPortNvmeMiniportEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnvmeminiportevent)

[**StorPortEtwChannelEvent4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwchannelevent4)

[**StorPortEtwChannelEvent8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwchannelevent8)

[**StorPortEtwEvent2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent2)

[**StorPortEtwEvent4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent4)

[**StorPortEtwEvent8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent8)