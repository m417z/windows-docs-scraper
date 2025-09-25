# IDataModelScriptDebugVariableSetEnumerator::GetNext

## Description

The GetNext method moves the enumerator to the next variable in the set and returns the variable's name, value, and any metadata associated with it. If the enumerator has hit the end of the set, the error E_BOUNDS is returned. Once the E_BOUNDS marker has been returned from the GetNext method, it will continue to produce E_BOUNDS when called again unless an intervening Reset call is made.

## Parameters

### `variableName`

The name of the variable in the set is returned here as a string allocated by the SysAllocString function. The caller is responsible for freeing the returned string via SysFreeString.

### `variableValue`

The current value of the variable is returned here. The value must be marshaled out to an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) representation. Every property or other construct on the [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) must be able to be acquired while the debugger is in a break state.

### `variableMetadata`

Optional metadata about the variable and its presentation may be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugVariableSetEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugvariablesetenumerator)