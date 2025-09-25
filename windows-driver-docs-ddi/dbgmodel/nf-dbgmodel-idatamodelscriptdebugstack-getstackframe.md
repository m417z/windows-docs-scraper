# IDataModelScriptDebugStack::GetStackFrame

## Description

The GetStackFrame gets a particular stack frame from the stack segment. The call stack has a zero based indexing system: the current stack frame where the break event occurred is frame 0. The caller of the current method is frame 1 (and so forth).

## Parameters

### `frameNumber`

The zero based index of the stack frame within this stack segment to retrieve. The top frame representing the current point where the debugger broke is frame 0. It's caller is frame 1 (and so forth).

### `stackFrame`

An interface to the given stack frame will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugStack interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstack)