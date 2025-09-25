# IDataModelScriptDebug::StopDebugging

## Description

The StopDebugging method is called by a client that wants to stop debugging. This method call may be made at any point after StartDebugging was made successfully (e.g.: during a break, while the script is executing, etc...). The call immediately ceases all debugging activity and resets the state back to before StartDebugging was called.

## Parameters

### `debugClient`

The debug client which is stopping debugging. This should match the debug client passed to the StartDebugging call. A non-matching client is an illegal call.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebug interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug)