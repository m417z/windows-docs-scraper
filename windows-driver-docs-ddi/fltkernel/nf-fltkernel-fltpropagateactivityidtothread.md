# FltPropagateActivityIdToThread function

## Description

The **FltPropagateActivityIdToThread** routine associates the activity ID from the IRP in the minifilter's callback data with the current thread.

## Parameters

### `CallbackData` [in]

Pointer to the callback data containing the request with an associated activity ID.

### `PropagateId` [in/out]

Pointer to a caller allocated **GUID** that stores the activity ID for the current thread.

### `OriginalId` [out]

On return, the **GUID** pointer referenced by **OriginalId** points to the activity ID that was previously set for the thread.

## Return value

**FltPropagateActivityIdToThread** returns one of the following **NTSTATUS** values.

| Return code | Description |
| ----------- | ----------- |
| STATUS_NOT_SUPPORTED | The callback data does not contain a request for an IRP operation. |
| STATUS_NOT_FOUND | No activity ID is associated with the request in **CallbackData**. |
| STATUS_SUCCESS | An activity ID was returned in the **GUID** value pointed to by **OriginalId**. |

## Remarks

The **FltPropagateActivityIdToThread** routine is used by trace aware minifilters. A minifilter uses this routine to attach the activity ID from an IRP to a worker thread processing I/O for the request.

A minifilter must call **IoClearActivityIdThread** with the pointer in **OriginalId** before returning control from the worker thread if the call to **FltPropagateActivityIdToThread** was successful.

## See also

[**FltGetActivityIdCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetactivityidcallbackdata)

[**FltSetActivityIdCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetactivityidcallbackdata)