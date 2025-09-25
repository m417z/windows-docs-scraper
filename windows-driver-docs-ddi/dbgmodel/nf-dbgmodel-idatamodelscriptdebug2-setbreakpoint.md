# IDataModelScriptDebug2::SetBreakpoint

## Description

The SetBreakpoint method sets a breakpoint within the script. Note that the implementation is free to adjust the inpassed line and column positions to move forward to an appropriate code position. The actual line and column numbers where the breakpoint was placed can be retrieved by method calls on the returned [IDataModelScriptDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugbreakpoint) interface.

Note that it is the responsibility of the implementation to "remember" all of the breakpoints which have been set and assign a unique identifier to each. That identifier must be unique within the domain of a single script.

As long as the script debugger is enabled via a call to the StartDebugging method, it is legal to call this method. A breakpoint may be set before any execution occurs.

## Parameters

### `linePosition`

The one based line number of the location in source code where the breakpoint is being set.

### `columnPosition`

The one based column number on the given line where the breakpoint is being set.

### `breakpoint`

An [IDataModelScriptDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugbreakpoint) interface representing the newly created breakpoint is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## See also

[IDataModelScriptDebug2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug2)