## Description

This function frees any resources that were allocated during creation of the telemetry data report.

## Parameters

### `TelemetryHandle`

Supplies a Telemetry Report handle created by [LkmdTelCreateReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelcreatereport).

## Remarks

This function must be called or else system memory is leaked.

## See also

[LkmdTelCreateReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelcreatereport)