# IDataModelScriptDebugStackFrame::EnumerateArguments

## Description

Enumerates arguments to the function in this frame.

The EnumerateArguments method returns a variable set (represented by an [IDataModelScriptDebugVariableSetEnumerator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugvariablesetenumerator) interface) for all function arguments of the function called in the stack frame represented by the [IDataModelScriptDebugStackFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe) interface on which this method was called.

## Parameters

### `variablesEnum`

A variable set enumerator which enumerates all function arguments of the function called in the given stack frame.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugStackFrame interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe)