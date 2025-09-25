# IStiDeviceControl::WriteToErrorLog

## Description

The **IStiDeviceControl::WriteToErrorLog** method allows a user-mode still image minidriver to write a message into the still image error log.

## Parameters

### `dwMessageType`

Caller-supplied constant value representing the message type. The following values are defined in *Sti.h*:

STI_TRACE_INFORMATION

STI_TRACE_WARNING

STI_TRACE_ERROR

### `pszMessage`

Caller-supplied pointer to a message string to be written to the log file.

### `dwErrorCode`

*Not used*.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The still image error log file is named *sti_trace.log* and is located in the Windows directory. Control Panel allows a user to select which still image error types (informational, warning, or error) are written to the error log (see [Nonmodifiable Registry Entries](https://learn.microsoft.com/windows-hardware/drivers/image/registry-entries-for-still-image-devices)).

Error messages should be reserved for critical error conditions, such as device hardware failures. Informational messages can be used for your own debugging purposes. Logged messages aren't visible to users, but they might be used by a support engineer to help debug a user's problems.

A still image minidriver receives an **IStiDeviceControl** interface pointer as input to its [IStiUSD::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/stiusd/nf-stiusd-istiusd-initialize) method.