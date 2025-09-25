# IDataModelScriptDebugStackFrame::IsTransitionPoint

## Description

The [IDataModelScriptDebugStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstack) interface represents a segment of a call stack -- that portion of the call stack which is contained within the context of one script. If the debugger is capable of detecting the transition from one script to another (or one script provider to another), it can indicate this by implementing the IsTransitionPoint method and returning true or false as appropriate. The call stack frame which entered the script where the segment applies should be considered a transition point. All other frames are not.

It is perfectly legal for any script debugger which is incapable of doing cross-script debugging or detection to simply return E_NOTIMPL from this method. In such cases, the debug interface may only be able to show a stack backtrace for the current script even if the overall call stack spans multiple scripts.

## Parameters

### `isTransitionPoint`

If this stack frame is the first frame which entered a particular script or script provider, it should return true here indicating that the frame is a transition point from one script/provider to another. For any other stack frame, false should be returned.

## Return value

This method returns HRESULT which indicates success or failure. Debuggers which are incapable of detecting transition points may return E_NOTIMPL from this method.

## Remarks

## See also

[IDataModelScriptDebugStackFrame interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebugstackframe)