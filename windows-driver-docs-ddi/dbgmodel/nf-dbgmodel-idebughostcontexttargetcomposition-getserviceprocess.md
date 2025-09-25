## Description

The GetServiceProcess method retrieves the process that is associated with a particular host context.

## Parameters

### `ppProcess`

A pointer to a pointer variable that receives the ISvcProcess interface.

## Return value

If the method succeeds, it returns S_OK. If the context refers to something above the level of a specific process, this method will return an E_FAIL. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostContextTargetComposition interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontexttargetcomposition)