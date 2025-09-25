# PFN_WSK_CLIENT_EVENT callback function

## Description

The
*WskClientEvent* event callback function notifies a WSK application about events that are not specific
to a particular socket.

## Parameters

### `ClientContext` [in, optional]

A pointer to the context value that was specified by the
*WskClientNpi* parameter passed to the
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister) function.

### `EventType` [in]

The specific event about which the WSK application is being notified. There are currently no events defined.

### `Information` [in, optional]

A pointer to a buffer that contains additional information that is associated with the event. If
there is no additional information associated with the event, this pointer will be **NULL**.

### `InformationLength` [in]

The length of the additional information that is contained in the buffer that is pointed to by the
*Information* parameter. If there is no additional information associated with the event, this value
will be zero.

## Return value

A WSK application's
*WskClientEvent* event callback function can return one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The event notification was successfully processed. |
| **STATUS_NOT_IMPLEMENTED** | Support for the event that is passed in the *Event* parameter is not implemented. |

## Remarks

Currently, no events are defined for the
*WskClientEvent* event callback function. Therefore, if a WSK application implements a
*WskClientEvent* event callback function, it should always return STATUS_NOT_IMPLEMENTED.

The additional information that is contained in the buffer that is pointed to by the
*Information* parameter is read-only and is valid only for the duration of the call to the
*WskClientEvent* event callback function.

If a WSK application does not implement a
*WskClientEvent* event callback function, it should set the
*WskClientEvent* member of the
[WSK_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_dispatch) structure to **NULL**
before it calls
[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister).

The WSK subsystem calls a WSK application's
*WskClientEvent* event callback function at IRQL <= DISPATCH_LEVEL.

A WSK application's *WskClientEvent* event callback function must not wait for completion of other WSK requests in the context of WSK completion or event callback functions. The callback can initiate other WSK requests (assuming that it doesn't spend too much time at DISPATCH_LEVEL), but it must not wait for their completion even when the callback is called at IRQL = PASSIVE_LEVEL.

## See also

[WSK_CLIENT_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_dispatch)

[WskRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskregister)