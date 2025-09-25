# WS_FAULT_DISCLOSURE enumeration

## Description

Controls how much error information is included in a fault.
Since the error object may contain sensitive
data as part of the error string, it is not
always appropriate to include the error strings
information in all faults.

## Constants

### `WS_MINIMAL_FAULT_DISCLOSURE:0`

Use a generic fault string for all errors.

### `WS_FULL_FAULT_DISCLOSURE:1`

Use the error string as the fault string.