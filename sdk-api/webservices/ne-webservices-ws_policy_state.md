# WS_POLICY_STATE enumeration

## Description

The state of the policy object.

## Constants

### `WS_POLICY_STATE_CREATED:1`

The initial state of the policy object.

### `WS_POLICY_STATE_FAULTED:2`

The policy object is no longer usable due to a previous error.

## Remarks

The following diagram illustrates the functions that
cause state transitions in the policy object.
:::image type="content" source="./images/PolicyStates.png" border="false" alt-text="Diagram of the state transitions for a Policy object showing the functions that cause transitions between the Created and Faulted states.":::