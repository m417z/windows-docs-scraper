# _DXGKARG_UPDATEHWCONTEXTSTATE structure

## Description

Used to update the context state.

## Members

### `hHwContext`

The hardware context whose priority or execution state is being changed.

### `ContextSwitchFence`

Context switch fence value associated with this state change request.

### `Priority`

Execution priority of this context relative to other running contexts on this node.

### `Flags`

Context execution state flags.