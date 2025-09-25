# IWorkspaceReportMessage::RegisterErrorEvent

## Description

Registers the specified error event message to use in the UI.

## Parameters

### `bstrWkspId` [in]

A string containing the workspace ID in which the error event is to be registered.

### `dwErrorType` [in]

The error type of the event.

### `bstrErrorMessageType` [in]

A string containing the error message.

### `dwErrorCode` [in]

The error code for the event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceReportMessage](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacereportmessage)