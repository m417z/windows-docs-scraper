# IDataModelScriptDebugStack::GetFrameCount

## Description

The GetFrameCount method returns the number of stack frames in this segment of the call stack. If the provider can detect frames in different script contexts or of different providers, it should indicate this to the caller by implementation of the IsTransitionPoint and GetTransition methods on the entry frame into this stack segment.

## Return value

This method returns ULONG64. The value is the number of stack frames in the current stack segment.

## Remarks

## See also

[IDataModelScriptDebugStack interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstack)