# IStillImageW::WriteToErrorLog

## Description

The **IStillImage::WriteToErrorLog** method writes a message to the still image error log.

## Parameters

### `dwMessageType`

Caller-supplied constant value representing the message type. The following values are defined in *Sti.h*:

STI_TRACE_INFORMATION

STI_TRACE_WARNING

STI_TRACE_ERROR

### `pszMessage` [in]

Caller-supplied pointer to the message string to be written to the log file.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The still image error log file is named *sti_trace.log* and is located in the Windows directory. Registry values determine which still image error types (informational, warning, or error) are written to the error log (see [Nonmodifiable Registry Entries](https://learn.microsoft.com/windows-hardware/drivers/image/registry-entries-for-still-image-devices)).

Error messages should be reserved for critical error conditions, such as device hardware failures. Informational messages can be used for your own debugging purposes. Logged messages aren't visible to users, but they might be used by a support engineer to help debug a user's problems.

Before calling **IStillImage::WriteToErrorLog**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.