# AllJoynConnectToBus function

## Description

Opens the AllJoyn Router Node Service named pipe, and sets it to **PIPE_NOWAIT**.

## Parameters

### `connectionSpec` [in, optional]

Optional parameter to pass connection spec for future use.

## Return value

The client side handle.

| Return code | Description |
| --- | --- |
| **INVALID_HANDLE_VALUE** | An error occurred. Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for more information. The app can retry the [ConnectToBus](https://learn.microsoft.com/previous-versions/windows/desktop/api/msajtransport/nf-msajtransport-alljoynconnecttobus) in case of GetLastError() == **ERROR_PIPE_BUSY**. In AllJoyn, we allow multiple instances of server, so **ERROR_PIPE_BUSY** is not expected to occur in a normal use case. |