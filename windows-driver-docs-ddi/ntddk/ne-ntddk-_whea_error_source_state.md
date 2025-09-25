# _WHEA_ERROR_SOURCE_STATE enumeration

## Description

The WHEA_ERROR_SOURCE_STATE enumeration defines the different runtime states for an error source.

## Constants

### `WheaErrSrcStateStopped`

The error source is stopped.

### `WheaErrSrcStateStarted`

The error source is started.

### `WheaErrSrcStateRemoved`

The error source is removed.

### `WheaErrSrcStateRemovePending`

The error source is pending.

## Remarks

The [WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure contains a member of type WHEA_ERROR_SOURCE_STATE that indicates the runtime state of the error source.

## See also

[WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)