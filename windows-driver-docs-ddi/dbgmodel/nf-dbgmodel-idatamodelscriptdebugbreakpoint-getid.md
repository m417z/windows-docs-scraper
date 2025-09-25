# IDataModelScriptDebugBreakpoint::GetId

## Description

The GetId method returns the unique identifier assigned by the script provider's debug engine to the breakpoint. This identifier must be unique within the context of the containing script. The breakpoint identifier may be unique to the provider; however, that is not required.

## Return value

This method returns ULONG64. The value is the unique identifier assigned to the breakpoint.

## Remarks

## See also

[IDataModelScriptDebugBreakpoint interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugbreakpoint)