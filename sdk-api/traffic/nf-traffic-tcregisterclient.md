# TcRegisterClient function

## Description

The
**TcRegisterClient** function is used to register a client with the traffic control interface (TCI). The
**TcRegisterClient** function must be the first function call a client makes to the TCI.

Client registration provides callback routines that allow the TCI to complete either client-initiated operations or asynchronous events. Upon successful registration, the caller of the
**TcRegisterClient** function must be ready to have any of its TCI handlers called. See
[Entry Points Exposed by Clients of the Traffic Control Interface](https://learn.microsoft.com/previous-versions/windows/desktop/qos/entry-points-exposed-by-clients-of-the-traffic-control-interface) for more information.

## Parameters

### `TciVersion` [in]

Traffic control version expected by the client, included to ensure compatibility between traffic control and the client. Clients can pass CURRENT_TCI_VERSION, defined in Traffic.h.

### `ClRegCtx` [in]

Client registration context. *ClRegCtx* is returned when the client's notification handler function is called. This can be a container to hold an arbitrary client-defined context for this instance of the interface.

### `ClientHandlerList` [in]

Pointer to a list of client-supplied handlers. Client-supplied handlers are used for notification events and asynchronous completions. Each completion routine is optional, with the exception of the notification handler. Setting the notification handler to **NULL** will return an ERROR_INVALID_PARAMETER.

### `pClientHandle` [out]

Pointer to the buffer that traffic control uses to return a registration handle to the client.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system is out of memory. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is **NULL**. |
| **ERROR_INCOMPATIBLE_TCI_VERSION** | The TCI version is wrong. |
| **ERROR_OPEN_FAILED** | Traffic control failed to open a system device. The likely cause is insufficient privileges. |
| **ERROR_TOO_MANY_CLIENTS** | Traffic Control was unable to register with the kernel component GPC. The likely cause is too many traffic control clients are currently connected.<br><br>**Windows 2000:** This value is not supported. |

## Remarks

Some of the return codes can be found in tcerror.h.

**Note** Use of the
**TcRegisterClient** function requires administrative privilege.