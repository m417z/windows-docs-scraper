# _POWER_THROTTLING_PROCESS_STATE structure

## Description

Stores the throttling policies and how to apply them to a target process when that process is subject to power management.

## Members

### `Version`

The version of this structure. Set to PROCESS_POWER_THROTTLING_CURRENT_VERSION.

### `ControlMask`

Flags that enable the caller to take control of the power throttling mechanism.

* PROCESS_POWER_THROTTLING_EXECUTION_SPEED: Manages the execution speed of the process.

### `StateMask`

Flags that manage the power throttling mechanism on/off state.

* PROCESS_POWER_THROTTLING_EXECUTION_SPEED: Manages the execution speed of the process.