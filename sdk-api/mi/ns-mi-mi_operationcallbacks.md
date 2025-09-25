# MI_OperationCallbacks structure

## Description

Structure that holds all callback function pointers for carrying out operations.

## Members

### `callbackContext`

A client specific context that is passed to all the callbacks. This is used to correlate the callback to the associated operation. This value will be passed to any operation callbacks.

### `promptUser`

Optional callback to handle prompt user requests from the server.

### `writeError`

Optional callback to receive write error messages from the server.

### `writeMessage`

Optional callback to receive write messages from the server.

### `writeProgress`

Optional callback to receive progress reports from the server.

### `instanceResult`

Optional instance callback to get asynchronous results from an operation. If this is not specified and the operation is an instance operation, then the client will need to use the synchronous APIs to retrieve the results.

### `indicationResult`

Optional instance callback to get indication (subscribe) results from an operation. If this is not specified and the operation is an instance operation, then the client will need to use the synchronous APIs to retrieve the results.

### `classResult`

Optional instance callback to get classes and class options from an operation. If this is not specified and the operation is an instance operation, then the client will need to use the synchronous APIs to retrieve the results.

### `streamedParameterResult`

Optional callback to get streamed parameter results from method invocation operations.

## Remarks

All PowerShell Semantics and streamed result callbacks are optional; include the callbacks
you want to receive. If the associated operation callback for the operation
is not set, i.e. set to **NULL**, the operation will be carried out synchronously. The client must call into the appropriate MI_Operation function to receive the results. The result callbacks will continue to be called until the moreResults field is equal to MI_FALSE.

## See also

[MI_OperationCallback_Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn792325(v=vs.85))

[MI_OperationCallback_Indication](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn792326(v=vs.85))

[MI_OperationCallback_Instance](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn792327(v=vs.85))

[MI_OperationCallback_PromptUser](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn792328(v=vs.85))

[MI_OperationCallback_StreamedParameter](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn792329(v=vs.85))

[MI_OperationCallback_WriteError](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn792330(v=vs.85))

[MI_OperationCallback_WriteMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759645(v=vs.85))

[MI_OperationCallback_WriteProgress](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759646(v=vs.85))