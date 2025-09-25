# ScriptDebugEventInformation structure

## Description

A struct containing information about a particular debug event.

## Members

### `DebugEvent`

### `EventPosition`

The line/column of script at which the debug event occurred (0 values : cannot determine)

### `EventSpanEnd`

The ending line/column of script at which the debug event occurred (0 values : cannot determine)

### `u`

### `u.ExceptionInformation`

### `u.ExceptionInformation.IsUncaught`

### `u.BreakpointInformation`

### `u.BreakpointInformation.BreakpointId`

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)