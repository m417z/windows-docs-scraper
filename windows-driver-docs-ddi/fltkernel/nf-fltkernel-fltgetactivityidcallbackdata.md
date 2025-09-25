# FltGetActivityIdCallbackData function

## Description

The **FltGetActivityIdCallbackData** routine retrieves the current activity ID associated with a request in a minifilter's callback data.

## Parameters

### `CallbackData` [in]

A pointer to the callback data containing the request with an associated activity ID.

### `Guid` [out]

A pointer to the GUID structure receiving the activity ID.

## Return value

**FltGetActivityIdCallbackData** returns one of the following **NTSTATUS** values.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_SUPPORTED** | The callback data does not contain a request for an IRP operation. |
| **STATUS_NOT_FOUND** | No activity ID is associated with the request in *CallbackData*. |
| **STATUS_SUCCESS** | An activity ID was returned in the **GUID** value pointed to by *Guid*. |

## See also

[FltPropagateActivityIdToThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpropagateactivityidtothread)

[FltSetActivityIdCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetactivityidcallbackdata)