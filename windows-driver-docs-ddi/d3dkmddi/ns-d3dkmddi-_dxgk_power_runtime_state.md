# _DXGK_POWER_RUNTIME_STATE structure

## Description

Describes the characteristics of an idle state (an F-state).

## Members

### `TransitionLatency`

The amount of time, in 100-nanosecond units, that the component takes to return to the F0 state.
This value should be zero for the F0 state.

### `ResidencyRequirement`

The minimal amount of time, in 100-nanosecond units, that is required to spend in
this F-state to make it worthwhile. This value should be zero for the F0 state.

### `NominalPower`

The power draw, in microwatt units, of the component in this F-state. This value should not be zero for the F0 state.

## Remarks

F-states in hardware must be defined such that a deeper F-state (higher F-value) will use less power and take longer to return to the latent F0 state.