# NVME_AUTO_POWER_STATE_TRANSITION_ENTRY structure

## Description

Contains a 64 bit entry specifying information about idle time and power state transition for each of the allowable 32 power states. The entries begin with power state 0 and then increase sequentially. For example, power state 0 is described in bytes 7:0, power state 1 is described in bytes 15:8, and so on. The data structure is 256 bytes in size and should be physically contiguous.

For power states that are not supported, the unused **NVME_AUTO_POWER_STATE_TRANSITION_ENTRY** data structure entries will be cleared to all zeroes.

## Members

### `Reserved0`

Bits 0-2 are reserved.

### `IdleTransitionPowerState`

Idle Transition Power State (ITPS) specified in Bits 3-7 is the non-operational power state for the controller to autonomously transition to after there is a continuous period of idle time in the current power state that exceeds the time specified in the **IdleTimePriorToTransition** field.

### `IdleTimePriorToTransition`

Idle Time Prior to Transition (ITPT) specified in Bits 8-31 is the amount of idle time that occurs in this power state prior to transitioning to the Idle Transition Power State. The time is specified in milliseconds. A value of 0h disables the autonomous power state transition feature for this power state.

### `Reserved1`

Bits 32-63 are reserved.

## Remarks

This structure is used in the Autonomous Power State Transition Enable (**APSTE**) parameter of the [NVME_CDW11_FEATURE_AUTO_POWER_STATE_TRANSITION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_auto_power_state_transition) structure.

## See also