# IWorkspaceReportMessage::IsErrorMessageRegistered

## Description

Determines whether a specified error message is registered in a specified workspace.

## Parameters

### `bstrWkspId` [in]

A string containing the ID of the workspace to check.

### `dwErrorType` [in]

The error type associated with the error message.

### `bstrErrorMessageType` [in]

A string containing the error message type.

### `dwErrorCode` [in]

The error code of the event.

### `pfErrorExist` [out, retval]

On success, returns a pointer to **VARIANT_TRUE** if the error message is registered in the specified workspace; otherwise, **VARIANT_FALSE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceReportMessage](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacereportmessage)