## Description

This function sets the secondary data in the telemetry data structure. It is not required prior to submitting a report. Providing secondary data allows a component to supply extra data within the minidump to assist in debugging.

## Parameters

### `TelemetryHandle`

Supplies a telemetry handle created by [LkmdTelCreateReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelcreatereport).

### `SecondaryDataGuid`

This is the GUID used to define the secondary data in the minidump.

### `SecondaryDataSize`

This is the size of the buffer for secondary data.

### `SecondaryDataBuffer`

This is the secondary data buffer.

## Return value

STATUS_SUCCESS if successful.

## Remarks

- This function can only be called one time per dump file. The buffer passed to this API must remain valid until after a call and return from [LkmdTelSubmitReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelsubmitreport).
- The size of the data should be less than 24 MB, although the actual size may vary based on the Windows version or system configuration. Data that exceeds the limit will be truncated.
- For more information, see [Secondary callback data](https://learn.microsoft.com/windows-hardware/drivers/debugger/reading-bug-check-callback-data).

## See also

[LkmdTelSubmitReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelsubmitreport)