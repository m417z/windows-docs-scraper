# IDebugHostScriptHost::CreateContext

## Description

The CreateContext method is called by a script provider to create a new context in which to place the contents of the script. Such context is represented by the [IDataModelScriptHostContext interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripthostcontext).

## Parameters

### `script`

The script for which to create a new context.

### `scriptContext`

The newly created script host context is returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptHostContext interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripthostcontext)

[IDebugHostScriptHost interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostscripthost)