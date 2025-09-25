# IDataModelScriptDebugBreakpoint::Remove

## Description

The Remove method removes the breakpoint from its containing list. The breakpoint no longer semantically exists after this method returns. The [IDataModelScriptDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugbreakpoint) interface which represented the breakpoint is considered orphaned after the call. Nothing else can (legally) be done with it after this call other than releasing it.

## Remarks

## See also

[IDataModelScriptDebugBreakpoint interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugbreakpoint)