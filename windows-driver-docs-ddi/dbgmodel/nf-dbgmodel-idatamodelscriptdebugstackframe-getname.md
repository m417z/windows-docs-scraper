# IDataModelScriptDebugStackFrame::GetName

## Description

The GetName method returns the display name (e.g.: function name) of this frame. Such name will be displayed within the stack backtrace presented to the user in the debugger interface.

## Parameters

### `name`

The display name (e.g.: function name) of the frame is returned here as a string allocated via the SysAllocString method. The caller is responsible for freeing this string with SysFreeString.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebugStackFrame interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe)