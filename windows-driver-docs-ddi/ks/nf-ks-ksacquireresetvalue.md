# KsAcquireResetValue function

## Description

The **KsAcquireResetValue** function retrieves the current reset state from an IOCTL_KS_RESET_STATE IRP.

## Parameters

### `Irp` [in]

Points to the IRP from which to retrieve the reset state.

### `ResetValue` [out]

Points to a caller-allocated buffer, that on successful completion contains the reset value (KSRESET_BEGIN, KSRESET_END) associated with the IRP.

## Return value

The **KsAcquireResetValue** function returns STATUS_SUCCESS if the reset value was obtained.