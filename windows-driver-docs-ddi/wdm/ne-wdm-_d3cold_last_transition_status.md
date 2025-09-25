# _D3COLD_LAST_TRANSITION_STATUS enumeration

## Description

The **D3COLD_LAST_TRANSITION_STATUS** enumeration indicates whether the most recent transition to the D3hot device power state was followed by a transition to the D3cold device power state.

## Constants

### `LastDStateTransitionStatusUnknown`

Information is not available from the bus driver or platform firmware about whether the most recent transition to D3hot was followed by a transition to D3cold.

### `LastDStateTransitionD3hot`

The most recent transition to the D3hot device power state was not followed by a transition to the D3cold device power state.

### `LastDStateTransitionD3cold`

The most recent transition to the D3hot device power state was followed by a transition to the D3cold device power state.

## Remarks

The *LastTransitionStatus* parameter of the [GetLastTransitionStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_d3cold_last_transition_status) routine is a pointer to a variable of type **D3COLD_LAST_TRANSITION_STATUS**.

## See also

[GetLastTransitionStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_d3cold_last_transition_status)