# FsRtlCompleteRequest macro

## Description

The **FsRtlCompleteRequest** macro completes an IRP with the specified status.

## Parameters

### `IRP`

Pointer to the IRP to be completed.

### `STATUS`

Status value to be returned for the IRP.

## See also

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)