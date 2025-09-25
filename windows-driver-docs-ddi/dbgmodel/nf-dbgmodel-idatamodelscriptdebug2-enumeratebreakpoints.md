# IDataModelScriptDebug2::EnumerateBreakpoints

## Description

The EnumerateBreakpoints method returns an enumerator capable of enumerating every breakpoint which is set within a particular script.

As long as the script debugger is enabled via a call to the StartDebugging method, it is legal to call this method.

## Parameters

### `breakpointEnum`

An enumerator which enumerates every breakpoint which is set within the script (whether enabled or disabled) must be returned here.

## Return value

This method returns HRESULT.

## See also

[IDataModelScriptDebug2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug2)