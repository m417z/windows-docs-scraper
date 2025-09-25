# _STORPORT_TELEMETRY_EVENT structure

## Description

The **STORPORT_TELEMETRY_EVENT** structure describes the miniport telemetry data payload.

## Members

### `DriverVersion`

Miniport driver version.

### `EventId`

A miniport defined identifier for the telemetry event.

### `EventName`

A miniport defined name for the telemetry event, which has the maximum length of **EVENT_NAME_MAX_LENGTH**.

### `EventVersion`

A miniport defined version for the telemetry event.

### `Flags`

Reserved.

### `EventBufferLength`

The length of **EventBuffer**, which should be not larger than **EVENT_BUFFER_MAX_LENGTH** that is 4KB.

### `EventBuffer`

A miniport defined telemetry payload, the length of which is **EventBufferLength**.

### `ParameterName0`

A description of the of the meaning of ParameterValue0. This parameter name string must be <= EVENT_MAX_PARAM_NAME_LEN.

### `ParameterValue0`

The value for parameter 0.

### `ParameterName1`

A description of the of the meaning of ParameterValue1. This parameter name string must be <= EVENT_MAX_PARAM_NAME_LEN.

### `ParameterValue1`

The value for parameter 1.

### `ParameterName2`

A description of the of the meaning of ParameterValue2. This parameter name string must be <= EVENT_MAX_PARAM_NAME_LEN.

### `ParameterValue2`

The value for parameter 2.

### `ParameterName3`

A description of the of the meaning of ParameterValue3. This parameter name string must be <= EVENT_MAX_PARAM_NAME_LEN.

### `ParameterValue3`

The value for parameter 3.

### `ParameterName4`

A description of the of the meaning of ParameterValue4. This parameter name string must be <= EVENT_MAX_PARAM_NAME_LEN.

### `ParameterValue4`

The value for parameter 4.

### `ParameterName5`

A description of the of the meaning of ParameterValue5. This parameter name string must be <= EVENT_MAX_PARAM_NAME_LEN.

### `ParameterValue5`

The value for parameter 5.

### `ParameterName6`

A description of the of the meaning of ParameterValue6. This parameter name string must be <= EVENT_MAX_PARAM_NAME_LEN.

### `ParameterValue6`

The value for parameter 6.

### `ParameterName7`

A description of the of the meaning of ParameterValue7. This parameter name string must be <= EVENT_MAX_PARAM_NAME_LEN.

### `ParameterValue7`

The value for parameter 7.

## Remarks

A **STORPORT_TELEMETRY_EVENT** structure describes the miniport telemetry data payload. The miniport should fill it when calling StorPortLogTelemetry.

## See also

[StorPortLogTelemetry](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogtelemetry)