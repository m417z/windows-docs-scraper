# PROCESS_MEMORY_EXHAUSTION_TYPE enumeration

## Description

Represents the different memory exhaustion types.

## Constants

### `PMETypeFailFastOnCommitFailure`

Anytime memory management fails an allocation due to an inability to commit memory, it will cause the process to trigger a Windows Error Reporting report and then terminate immediately with **STATUS_COMMITMENT_LIMIT**.
The failure cannot be caught and handled by the app.

### `PMETypeMax`

The maximum value for this enumeration. This value may change in a future version.