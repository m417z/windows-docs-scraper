# IDataModelScriptDebug2::GetDebugState

## Description

The GetDebugState method returns the current state of the script (e.g.: whether it is executing or not). The state is defined by a value within the ScriptDebugState enumeration which is defined as follows.

Enumerant | Description
|---------|-------------|
ScriptDebugNoDebugger | Indicates that debugging is not active on the script. This means that the StartDebugging method has not yet been called on this script or that StopDebugging has already been called. In either case, further interaction with the script debugger on the given script is invalid until the debugger is started.
ScriptDebugNotExecuting | Indicates that no code within the script is actively executing. Returning this as opposed to ScriptDebugNoDebugger indicates that the script is being debugged -- that is, the StartDebugging method has been successfully called on its debug interface.
ScriptDebugExecuting | Indicates that the script is actively executing code and is not broken into the debugger.
ScriptDebugBreak | Indicates that the script is broken into the debugger during the execution of code within the script

## Return value

The debug state of the script as indicated by a value in the ScriptDebugState enumeration.

## See also

[IDataModelScriptDebug2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug2)