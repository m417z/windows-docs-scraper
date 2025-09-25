# StorPortLogTelemetry function

## Description

The **StorPortLogTelemetry** routine logs a miniport telemetry event to help diagnose or collect any useful information. The miniport can log eight general purpose name-value pairs and a buffer that has maximum length of 4KB, as well as several event related fields that are defined in structure [STORPORT_TELEMETRY_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_storport_telemetry_event).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `StorAddress` [in, optional]

The storage unit device address. This parameter is NULL for adapter devices.

### `Event` [in]

Pointer to the STORPORT_TELEMETRY_EVENT structure that contains the telemetry data payload.

## Return value

**StorPortLogTelemetry** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INVALID_BUFFER_SIZE** | **EventBufferLength** is larger than **EVENT_BUFFER_MAX_LENGTH**. |
| **STOR_STATUS_INVALID_PARAMETER** | A pointer to one of the parameters is NULL or the EventBufferLength/EventBuffer in Event structure not matching. |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STATUS_SUCCESS** | The telemetry event data have been successfully logged. |

## Remarks

If any parameter in Event structure is not named, Event->ParameterNameX == NULL, the routine will set the corresponding parameter value to 0.

If miniport has no payload to fill in Event->EventBuffer, it should set Event->EventBufferLength = 0, as well as Event->EventBuffer = NULL.

## See also

[STORPORT_TELEMETRY_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_storport_telemetry_event)

[StorPortLogTelemetryEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogtelemetryex)