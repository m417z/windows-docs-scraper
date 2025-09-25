# IDataModelScriptDebug::GetStack

## Description

The GetStack method gets the current call stack at the break position. This method may only be called when the script is broken into the debugger.

## Parameters

### `stack`

A component implementing [IDataModelScriptDebugStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstack) is returned here representing the call stack state at the position of the break.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebug interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug)