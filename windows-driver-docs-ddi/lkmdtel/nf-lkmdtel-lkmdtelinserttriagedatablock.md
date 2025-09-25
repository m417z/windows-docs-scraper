## Description

This function adds a region of kernel memory to the kernel minidump.

## Parameters

### `TelemetryHandle`

Supplies a Telemetry Report handle created by [LkmdTelCreateReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelcreatereport).

### `TriageData`

Supplies the location of the triage data to be added.

### `TriageDataSize`

Supplies the number of bytes of triage data to add.

## Return value

STATUS_SUCCESS if successful.
STATUS_INVALID_PARAMETER if there is not already at least one triage data block present or an existing triage data block does not start on an 8 byte boundary.
STATUS_BUFFER_TOO_SMALL if there is insufficient space in the triage dump buffer to contain the new triage block.

## Remarks

- The buffers passed to this function must remain valid until the function returns. The function will copy the memory to new buffers.
- The maximum amount of memory that can be added via calls to `LkmdTelInsertTriageDataBlock` is dependent on the OS architecture. On a 64-bit OS, the maximum is approximately 180 KB. On a 32-bit OS, it is approximately 90 KB.

## See also

[LkmdTelCreateReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelcreatereport)