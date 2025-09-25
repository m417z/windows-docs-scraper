# IDataModelScriptDebug::SetEventFilter

## Description

The SetEventFilter method changes the "break on event" behavior for a particular event as defined by a member of the ScriptDebugEventFilter enumeration. A full list of available events (and a description of this enumeration) can be found in the documentation for the GetEventFilter method.

If a particular event type is not supported by the script debugger, E_NOTIMPL may be returned.

As long as the script debugger is enabled via a call to the StartDebugging method, it is legal to call this method.

## Parameters

### `eventFilter`

Indicates for which event the "break on event" behavior is being changed. The event is defined as a member of the ScriptDebugEventFilter enumeration.

### `isBreakEnabled`

If true, indicates that the caller wants the debugger to break into the debugger when the given event occurs; if false, indicates that the caller does not want the debugger to break into the debugger when the given event occurs.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebug interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug)