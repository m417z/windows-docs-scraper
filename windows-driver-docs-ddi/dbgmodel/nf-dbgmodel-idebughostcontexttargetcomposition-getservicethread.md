## Description

The GetServiceThread method retrieves the thread that is associated with a particular host context.

## Parameters

### `ppThread`

A pointer to a pointer variable that receives the ISvcThread interface.

## Return value

If the method succeeds, it returns S_OK. If the context refers to something above the level of a specific thread (most contexts do), this method will return an E_FAIL. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostContextTargetComposition interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontexttargetcomposition)