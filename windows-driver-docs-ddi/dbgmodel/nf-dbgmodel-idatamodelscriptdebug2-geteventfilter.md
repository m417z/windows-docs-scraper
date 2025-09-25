# IDataModelScriptDebug2::GetEventFilter

## Description

The GetEventFilter method returns whether "break on event" is enabled for a particular event. Events which can cause "break on event" are described by a member of the ScriptDebugEventFilter enumeration which is defined as follows:

Enumerant | Description
|---------|-------------|
ScriptDebugEventFilterEntry | Indicates that a break on every entry into the script from the outside should break into the debugger. The moment the scripting engine makes any call into script code, an immediate break should occur.
ScriptDebugEventFilterException | Indicates that the debugger should break whenever an exception occurs (what some debuggers might call a first chance exception). This break should occur before the event is handled in any way by script code.
ScriptDebugEventFilterUnhandledException | Indicates that the debugger should break if an unhandled exception occurs.
ScriptDebugEventFilterAbort | Indicates that the debugger should break if an abort occurs rather than simply aborting script execution.

If a particular event type is not supported by the script debugger, E_NOTIMPL may be returned.

As long as the script debugger is enabled via a call to the StartDebugging method, it is legal to call this method.

## Parameters

### `eventFilter`

Indicates for which event the "break on event" behavior is being changed. The event is defined as a member of the ScriptDebugEventFilter enumeration.

### `isBreakEnabled`

If "break on event" is enabled for the event in question, true is returned; otherwise, false is returned.

## Return value

This method returns HRESULT that indicates success or failure.

## See also

[IDataModelScriptDebug2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug2)