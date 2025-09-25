# IDataModelScriptDebugStackFrame::EnumerateLocals

## Description

The EnumerateLocals method returns a variable set (represented by an [IDataModelScriptDebugVariableSetEnumerator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugvariablesetenumerator) interface) for all local variables which are in scope in the context of the stack frame represented by the [IDataModelScriptDebugStackFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe) interface on which this method was called.

Note that if there are multiple definitions of a single variable where an inner scope eclipses an outer scope, only a single definition should be returned -- the definition which is in scope at the code position represented by the frame.

## Parameters

### `variablesEnum`

A variable set enumerator which enumerates all in-scope local variables at the code position represented by the stack frame.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugStackFrame interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe)