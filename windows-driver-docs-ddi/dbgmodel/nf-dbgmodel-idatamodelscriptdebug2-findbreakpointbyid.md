# IDataModelScriptDebug2::FindBreakpointById

## Description

Each breakpoint which is created within the script via the SetBreakpoint method is assigned a unique identifier (a 64-bit unsigned integer) by the implementation. The FindBreakpointById method is used to get an interface to the breakpoint from a given identifier.

As long as the script debugger is enabled via a call to the StartDebugging method, it is legal to call this method.

## Parameters

### `breakpointId`

The unique id of the breakpoint being retrieved.

### `breakpoint`

An interface to the found breakpoint is returned here. If the breakpoint cannot be found, an error is returned.

## Return value

This method returns HRESULT.

## Remarks

## See also

[IDataModelScriptDebug2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug2)