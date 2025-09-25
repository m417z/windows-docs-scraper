# PROCESS_POWER_THROTTLING_STATE structure

## Description

Specifies the throttling policies and how to apply them to a target process when that process is subject to power management. This structure is used by the [SetProcessInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessinformation) function.

## Members

### `Version`

The version of the **PROCESS_POWER_THROTTLING_STATE** structure.

| Value | Meaning |
| --- | --- |
| **PROCESS_POWER_THROTTLING_CURRENT_VERSION** | The current version. |

### `ControlMask`

This field enables the caller to take control of the power throttling mechanism.

| Value | Meaning |
| --- | --- |
| **PROCESS_POWER_THROTTLING_EXECUTION_SPEED** | Manages the execution speed of the process. |

### `StateMask`

Manages the power throttling mechanism on/off state.

| Value | Meaning |
| --- | --- |
| **PROCESS_POWER_THROTTLING_EXECUTION_SPEED** | Manages the execution speed of the process. |