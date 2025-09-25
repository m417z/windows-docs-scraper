## Description

This function creates the minidump file and notifies WER (Windows Error Reporting) that there is a pending report to be uploaded.

## Parameters

### `TelemetryHandle`

Supplies a Telemetry Report handle created by [LkmdTelCreateReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelcreatereport).

## Return value

STATUS_SUCCESS if successful.

STATUS_OBJECT_NAME_COLLISION, if attempting to create more than one report within the same one minute period. Only one report can be created per minute.

## Remarks

## See also

[LkmdTelCreateReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelcreatereport)