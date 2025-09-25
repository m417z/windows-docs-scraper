# FltSetActivityIdCallbackData function

## Description

The **FltSetActivityIdCallbackData** routine sets the activity ID for an IRP in a minifilter's callback data.

## Parameters

### `CallbackData` [in, out]

A pointer to the callback data containing the request with an associated activity ID.

### `Guid` [in, optional]

An optional pointer to the **GUID** structure receiving the activity ID. if *Guid* is **NULL**, the system will attempt to assign an ETW activity ID for the request.

## Return value

**FltSetActivityIdCallbackData** returns one of the following **NTSTATUS** values.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_SUPPORTED** | The callback data does not contain a request for an IRP operation.<br><br>-or-<br><br>The **GUID** pointed to by *Guid* is was not provided and no ETW activity ID is available or the operation. |
| **STATUS_NOT_FOUND** | No activity ID is associated with the request in *CallbackData*. |
| **STATUS_SUCCESS** | An activity ID pointed to by *Guid* was set for the IRP in *CallbackData*. |

## See also

[FltGetActivityIdCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetactivityidcallbackdata)

[FltPropagateActivityIdToThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpropagateactivityidtothread)