# IDataModelScriptDebug::StartDebugging

## Description

The StartDebugging method "turns on" the debugger for a particular script. The act of starting debugging does not actively cause any execution break or stepping. It merely makes the script debuggable and provides a set of interfaces for the client to communicate with the debugging interface.

The debug client which is passed to the StartDebugging method must be saved by the implementation. When any event occurs that "breaks into the debugger", that break is implemented by a synchronous call to notify the client of the event. Execution resumes when the client returns from notification call. A return argument indicates how execution should resume.

This method should only be called when the script debugger is not enabled for the given script. Any other call is illegal.

## Parameters

### `debugClient`

An interface to the client of the script debugger. Debug events are passed to this interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptDebug interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptdebug)