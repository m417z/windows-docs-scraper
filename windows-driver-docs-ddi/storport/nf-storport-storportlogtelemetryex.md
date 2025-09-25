# StorPortLogTelemetryEx function

## Description

The **StorPortLogTelemetry** routine logs a miniport telemetry event to help diagnose or collect any useful information.

## Parameters

### `HwDeviceExtension`

Pointer to the hardware device extension for the host bus adapter (HBA).

### `StorAddress`

Storage unit device address. This parameter is NULL for adapter devices.

### `Event`

Pointer to the [STORPORT_TELEMETRY_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_storport_telemetry_event) structure that contains the telemetry data payload.

### `Category`

[STOR_TELEMETRY_CATEGORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_telemetry_category) enum value that specifies the category of telemetry to be logged.

## Return value

**StorPortLogTelemetryEx** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_INVALID_BUFFER_SIZE | **Event->EventBufferLength** is larger than EVENT_BUFFER_MAX_LENGTH. |
| STOR_STATUS_INVALID_PARAMETER | A pointer to one of the parameters is NULL or the EventBufferLength is set to zero for a non-NULL **Event->EventBuffer**. |
| STOR_STATUS_NOT_IMPLEMENTED | This function is not implemented on the active operating system. |
| STOR_STATUS_SUCCESS | The telemetry event was successfully logged. |

## Remarks

A miniport can call **StorPortLogTelemetryEx** to log a tracelogging measures or telemetry event with miniport-customized data. Miniports specify the event category type in *Category*.

The event data is encapsulated in the [STORPORT_TELEMETRY_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_storport_telemetry_event) structure to which *Event* points. The miniport can log eight general purpose name-value pairs and a buffer that has a maximum length of 4KB, as well as several event-related fields.

## See also

[STOR_TELEMETRY_CATEGORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_telemetry_category)

[STORPORT_TELEMETRY_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_storport_telemetry_event)

[**StorPortLogTelemetry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogtelemetry)