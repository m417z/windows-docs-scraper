# AR_STATE enumeration

## Description

Indicates the state of screen auto-rotation for the system. For example, whether auto-rotation is supported, and whether it is enabled by the user. This enum is a bitwise OR of one or more of the following values.

## Constants

### `AR_ENABLED:0x0`

 Auto-rotation is enabled by the user.

### `AR_DISABLED:0x1`

Auto-rotation is disabled by the user.

### `AR_SUPPRESSED:0x2`

Auto-rotation is currently suppressed by one or more process auto-rotation preferences.

### `AR_REMOTESESSION:0x4`

The session is remote, and auto-rotation is temporarily disabled as a result.

### `AR_MULTIMON:0x8`

The system has multiple monitors attached, and auto-rotation is temporarily disabled as a result.

### `AR_NOSENSOR:0x10`

The system does not have an auto-rotation sensor.

### `AR_NOT_SUPPORTED:0x20`

Auto-rotation is not supported with the current system configuration.

### `AR_DOCKED:0x40`

The device is docked, and auto-rotation is temporarily disabled as a result.

### `AR_LAPTOP:0x80`

The device is in laptop mode, and auto-rotation is temporarily disabled as a result.