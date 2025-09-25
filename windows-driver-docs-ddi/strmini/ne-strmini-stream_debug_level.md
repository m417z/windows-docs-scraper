# STREAM_DEBUG_LEVEL enumeration

## Description

The STREAM_DEBUG_LEVEL enumeration lists incrementally increasing levels of debugger output.

## Constants

### `DebugLevelFatal`

Display only information about nonrecoverable system failure.

### `DebugLevelError`

Display information about serious but recoverable error.

### `DebugLevelWarning`

Display warnings

### `DebugLevelInfo`

Display status information. System must remain responsive.

### `DebugLevelTrace`

Display trace information. System need not remain responsive

### `DebugLevelVerbose`

Display verbose trace information. System need not remain responsive.

### `DebugLevelMaximum`

Display maximum information.

## See also

[StreamClassDebugPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassdebugprint)