## Description

The GetServiceManager method retrieves the service manager container that is associated with a particular host context.

## Parameters

### `ppServiceManager`

A pointer to a pointer variable that receives the IDebugServiceManager interface.

## Return value

If the method succeeds, it returns S_OK. If the context refers to something "debugger centric" above the level of a specific debug target, this method will return an E_FAIL. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostContextTargetComposition interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontexttargetcomposition)