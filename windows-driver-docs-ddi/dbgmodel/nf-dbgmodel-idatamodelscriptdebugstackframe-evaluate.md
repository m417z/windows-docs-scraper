# IDataModelScriptDebugStackFrame::Evaluate

## Description

The Evaluate method evaluates an expression (of the language of the script provider) in the context of the stack frame represented by the [IDataModelScriptDebugStackFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe) interface on which this method was called. The result of the expression evaluation must be marshaled out of the script provider as an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). The properties and other constructs on the resulting [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) must all be able to be acquired while the debugger is in a break state.

## Parameters

### `pwszExpression`

An expression (of the language of the script provider) to evaluate in the context of the stack frame represented by the [IDataModelScriptDebugStackFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe) on which this method was called.

### `ppResult`

The result of the expression evaluation. The script provider construct must be marshaled out to an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) representation and all properties and constructs on that object must be able to be acquired while the debugger is in a break state.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugStackFrame interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe)