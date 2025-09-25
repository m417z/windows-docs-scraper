## Description

The **KsValidateClockCreateRequest** function validates the clock creation request and returns the create structure associated with the request.

This can only be called at PASSIVE_LEVEL.

## Parameters

### `Irp`

Specifies the IRP with the clock create request being handled.

### `ClockCreate` [out]

Specifies the clock create structure pointer passed to the create request.

## Return value

The **KsValidateClockCreateRequest** function returns STATUS_SUCCESS if successful, or an error if unsuccessful.