# IDataModelScriptClient::ReportError

## Description

If an error occurs during execution or invocation of the script, the script provider calls the ReportError method to notify the user interface of the error.

The script provider may call the ReportError method an arbitrary number of times during an Execute or InvokeMain operation. It is up to the client to determine how to present the error information to the user.

## Parameters

### `errClass`

The class of error which is being reported as a member of the ErrorClass enumeration. Further information about this enumeration can be found in the documentation for [IDebugHostErrorSink](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosterrorsink).

### `hrFail`

The HRESULT of the error which occurred. If the domain of the error was not an HRESULT, it should be converted to such by the most appropriate means.

### `message`

The error message which occurred.

### `line`

The one based line number of the script where the error occurred.

### `position`

The one based position (column number) within the line where the error occurred.

## Return value

This method returns HRESULT.

## Remarks

## See also

[IDataModelScriptClient interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptclient)