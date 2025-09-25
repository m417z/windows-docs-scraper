# FltGetRequestorSessionId function

## Description

The **FltGetRequestorSessionId** routine returns the session ID of the process that originally requested the specified I/O operation.

## Parameters

### `CallbackData` [in]

A pointer to the [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure specifying the I/O operation.

### `SessionId` [out]

A pointer to the session ID for the requesting operation.

## Return value

The **FltGetRequestorSessionId** routine returns STATUS_SUCCESS on success or STATUS_UNSUCCESSFUL on failure.

## Remarks

If a process has no session ID, the SessionId parameter refers to -1 and the **FltGetRequestorSessionId** routine returns STATUS_SUCCESS.

If the **FltGetRequestorSessionId** routine returns STATUS_UNSUCCESSFUL, *SessionId* is not valid.