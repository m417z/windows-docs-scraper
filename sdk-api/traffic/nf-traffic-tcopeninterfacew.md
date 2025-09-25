# TcOpenInterfaceW function

## Description

The
**TcOpenInterface** function opens an interface. The
**TcOpenInterface** function identifies and opens an interface based on its text string, which is available from a call to
[TcEnumerateInterfaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateinterfaces). Once an interface is opened, the client must be prepared to receive notification regarding the open interface, through traffic control's use of the interface context.

## Parameters

### `pInterfaceName` [in]

Pointer to the text string identifying the interface to be opened. This text string is part of the information returned in a previous call to
[TcEnumerateInterfaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateinterfaces).

### `ClientHandle` [in]

Handle used by traffic control to identify the client, obtained through the *pClientHandle* parameter of the client's call to
[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient).

### `ClIfcCtx` [in]

Client's interface–context handle for the opened interface. Used as a callback parameter by traffic control when communicating with the client about the opened interface. This can be a container to hold an arbitrary client-defined context for this instance of the interface.

### `pIfcHandle` [out]

Pointer to the buffer where traffic control can return an interface handle. The interface handle returned to *pIfcHandle* must be used by the client to identify the interface in subsequent calls to traffic control.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system is out of memory. |
| **ERROR_NOT_FOUND** | Traffic control failed to find an interface with the name provided in *pInterfaceName*. |
| **ERROR_INVALID_HANDLE** | The client handle is invalid. |

## Remarks

Use of the
**TcOpenInterface** function requires administrative privilege.

> [!NOTE]
> The traffic.h header defines TcOpenInterface as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ClNotifyHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_notify_handler)

[TcEnumerateInterfaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateinterfaces)

[TcRegisterClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcregisterclient)