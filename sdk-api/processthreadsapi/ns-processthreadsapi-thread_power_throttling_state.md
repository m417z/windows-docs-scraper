# THREAD_POWER_THROTTLING_STATE structure

## Description

Specifies the throttling policies and how to apply them to a target thread when that thread is subject to power management. This structure is used by the [SetThreadInformation function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadinformation).

## Members

### `Version`

The version of the **THREAD_POWER_THROTTLING_STATE** structure.

| Value | Meaning |
| --- | --- |
| THREAD_POWER_THROTTLING_CURRENT_VERSION | The current version. |

### `ControlMask`

This field enables the caller to take control of the power throttling mechanism.

| Value | Meaning |
| --- | --- |
| THREAD_POWER_THROTTLING_EXECUTION_SPEED | Manages the execution speed of the thread. |

### `StateMask`

Manages the power throttling mechanism on/off state.

| Value | Meaning |
| --- | --- |
| THREAD_POWER_THROTTLING_EXECUTION_SPEED | Manages the execution speed of the thread. |