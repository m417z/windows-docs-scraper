# STOR_TELEMETRY_CATEGORY enumeration

## Description

The STOR_TELEMETRY_CATEGORY enumerator indicates the category of the telemetry event being logged in [StorPortLogTelemetryEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogtelemetryex).

## Constants

### `StorTelemetryCategory`

Indicates that the telemetry event can be used for general purpose telemetry and diagnostics. This category maps to the MICROSOFT_KEYWORD_TELEMETRY category defined in *MicrosoftTelemetry.h*.

### `StorMeasuresCategory`

Indicates that the telemetry event can be used to feed into quality measures. This category maps to the MICROSOFT_KEYWORD_MEASURES category defined in *MicrosoftTelemetry.h*.

## Remarks

## See also

[StorPortLogTelemetryEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogtelemetryex)