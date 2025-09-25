## Description

An NVMe miniport driver calls the **StorPortNvmeMiniportEvent** function to log an ETW event to a specific channel with up to eight extra general purpose parameters.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the hardware device extension for the host bus adapter (HBA).

### `ControllerHandle`

[in/optional] For a fabric NVMe (NVMe-oF) miniport, if the event is controller-specific, **ControllerHandle** is Storport's handle for the NVMe controller; otherwise, the value is NULL.

### `NamespaceId`

[in] If the event is namespace-specific, **NamespaceId** is the namespace identifier; otherwise, it should be zero.

### `EventChannel`

[in] A [**STORPORT_ETW_EVENT_CHANNEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_event_channel) enumeration value that specifies the ETW channel where the event is logged.

### `EventId`

[in] Minipoort-specific event identifier to uniquely identify the type of event.

### `EventDescription`

[in] Required string that describes the event. The maximum size of the string is **STORPORT_ETW_MAX_DESCRIPTION_LENGTH** characters, not including the null terminator.

### `EventKeywords`

[in] Bitmask of STORPORT_ETW_EVENT_CHANNEL_*XXX* values to further characterize the event. Set to zero if no keywords are needed.

### `EventLevel`

[in] A [**STORPORT_ETW_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_level) value that specifies the level of the event.

### `EventOpcode`

[in] A [**STORPORT_ETW_EVENT_OPCODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_event_opcode) enumeration value that specifies the opcode of the event.

### `Parameter1Name`

[in] A short string that gives meaning to **Parameter1Value**. If **Parameter1Name** is NULL or an empty string, **Parameter1Value** is ignored. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter1Value`

[in] The value of the first parameter. If **Parameter1Name** is NULL or an empty string, Storport will log this value as zero.

### `Parameter2Name`

[in] A short string that gives meaning to **Parameter2Value**. If **Parameter2Name** is NULL or an empty string, **Parameter2Value** is ignored. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter2Value`

[in] The value of the second parameter. If **Parameter2Name** is NULL or an empty string, Storport will log this value as zero.

### `Parameter3Name`

[in] A short string that gives meaning to **Parameter3Value**. If **Parameter3Name** is NULL or an empty string, **Parameter3Value** is ignored. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter3Value`

[in] The value of the third parameter. If **Parameter3Name** is NULL or an empty string, Storport will log this value as zero.

### `Parameter4Name`

[in] A short string that gives meaning to **Parameter4Value**. If **Parameter4Name** is NULL or an empty string, **Parameter4Value** is ignored. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter4Value`

[in] The value of the fourth parameter. If **Parameter4Name** is NULL or an empty string, Storport will log this value as zero.

### `Parameter5Name`

[in] A short string that gives meaning to **Parameter5Value**. If **Parameter5Name** is NULL or an empty string, **Parameter5Value** is ignored. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter5Value`

[in] The value of the fifth parameter. If **Parameter5Name** is NULL or an empty string, Storport will log this value as zero.

### `Parameter6Name`

[in] A short string that gives meaning to **Parameter6Value**. If **Parameter6Name** is NULL or an empty string, **Parameter6Value** is ignored. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter6Value`

[in] The value of the sixth parameter. If **Parameter6Name** is NULL or an empty string, Storport will log this value as zero.

### `Parameter7Name`

[in] A short string that gives meaning to **Parameter7Value**. If **Parameter7Name** is NULL or an empty string, **Parameter7Value** is ignored. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter7Value`

[in] The value of the seventh parameter. If **Parameter7Name** is NULL or an empty string, Storport will log this value as zero.

### `Parameter8Name`

[in] A short string that gives meaning to **Parameter8Value**. If **Parameter8Name** is NULL or an empty string, **Parameter8Value** is ignored. The maximum size of the string is **STORPORT_ETW_MAX_PARAM_NAME_LENGTH** characters, not including the null terminator.

### `Parameter8Value`

[in] The value of the eighth parameter. If **Parameter8Name** is NULL or an empty string, Storport will log this value as zero.

## Return value

**StorPortNvmeMiniportEvent** returns a STOR_STATUS_SUCCESS if the event is successfully logged. Otherwise, it returns a value such as:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid. |
| **STOR_STATUS_UNSUCCESSFUL** | The operation failed for other internal reasons. |

## Remarks

A miniport can call **StorPortNvmeMiniportEvent** to log eight general-purpose ETW parameters. The ETW parameters are expressed as eight name-value pairs. If a parameter is not named (Parameter*X*Name = NULL), the routine will set the corresponding parameter value to 0.

Events generated from StorPort miniport drivers are logged in the channel specified by **EventChannel**.

## See also

[**STORPORT_ETW_EVENT_CHANNEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_event_channel)

[**STORPORT_ETW_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_level)

[**STORPORT_ETW_EVENT_OPCODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_event_opcode)