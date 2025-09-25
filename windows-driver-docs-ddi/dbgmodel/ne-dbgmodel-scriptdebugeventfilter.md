# ScriptDebugEventFilter enumeration

## Description

Defines the set of debug events / exceptions which the script debugger can (potentially) auto-break on.

## Constants

### `ScriptDebugEventFilterEntry`

Indicates that a break on *EVERY ENTRY* into the script from outside should break into the debugger.

### `ScriptDebugEventFilterException`

Indicates that any first chance exception should immediately break into the debugger.

### `ScriptDebugEventFilterUnhandledException`

ScriptDebugEventFilterUnhandledException: Indicates that unhandled exceptions should immediately break into the debugger.

### `ScriptDebugEventFilterAbort`

Indicates that an abort (core debugger BREAK/STOP this action) should break into the script debugger rather than aborting the script execution.

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)