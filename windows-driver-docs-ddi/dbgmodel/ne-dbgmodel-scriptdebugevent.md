# ScriptDebugEvent enumeration

## Description

Defines what debug event occurred.

A debug event is defined by a variant record known as a ScriptDebugEventInformation. Which fields in the event information are valid is largely defined by the DebugEvent member. It defines the kind of event which occurred as described by a member of the ScriptDebugEvent enumeration.

## Constants

### `ScriptDebugBreakpoint`

Indicates that a breakpoint was hit. Information about the particular breakpoint which was hit is contained in the BreakpointInformation portion of the union which contains the following:

- BreakpointId: The unique identifier for the breakpoint which was hit.

### `ScriptDebugStep`

Indicates that a step event occurred. No further information is provided.

### `ScriptDebugException`

Indicates that an exception occurred. Information about the particular exception which occurred is contained in the ExceptionInformaiton position of the union which contains the following:

- IsUncaught: Indicates whether or not the breakpoint is a first-chance (false) or an unhandled exception (true)

The data object for the event is the object which was thrown.

The ScriptDebugEventInformation will fill in .u.ExceptionInformation and the outpassed object is a data model conversion of the actual exception.

### `ScriptDebugAsyncBreak`

Indicates that an asynchronous break into the script occurred. This might be because of something like "break on entry" or "break on event"

## Remarks

Whenever any event occurs which breaks into the script debugger, the debug code itself makes a call to the interface via the NotifyDebugEvent method. This method is synchronous. No execution of the script will resume until the interface returns from the event. The definition of the script debugger is intended to be simple: there are absolutely no nested events requiring processing.

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)