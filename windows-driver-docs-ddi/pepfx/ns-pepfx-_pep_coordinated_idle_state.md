# _PEP_COORDINATED_IDLE_STATE structure (pepfx.h)

## Description

The **PEP_COORIDNATED_IDLE_STATE** structure describes a coordinated idle state to the OS.

## Members

### `Latency`

The latency of waking from this idle state, in 100ns units.

### `BreakEvenDuration`

Supplies the minimum time the state must be entered to amortize the cost of entering/exiting the state. Idle durations longer than this period should save power when compared to entering a lighter state for the same period.

### `DependencyCount`

Supplies the number of dependencies this coordinated state has on other coordinated states or on processors.

### `MaximumDependencySize`

Supplies the maximum size of a single dependency.

## See also

[PEP_COORDINATED_IDLE_STATE structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_coordinated_idle_state)

[PEP_NOTIFY_PPM_QUERY_COORDINATED_STATES notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)