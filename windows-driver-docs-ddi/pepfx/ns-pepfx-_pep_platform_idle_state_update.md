# _PEP_PLATFORM_IDLE_STATE_UPDATE structure (pepfx.h)

## Description

The **PEP_PLATFORM_IDLE_STATE_UPDATE** structure contains the updated properties of a platform idle state.

## Members

### `Version`

The current version number of this structure. Set this member to PEP_PLATFORM_IDLE_STATE_UPDATE_VERSION.

### `Latency`

The worst-case latency, in 100-nanosecond units, for the platform to wake from this idle state in response to a wake event.

### `BreakEvenDuration`

The minimum amount of time, specified in 100-nanosecond units, that the platform must spend in this idle state to make a transition to this state worthwhile. The Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) uses this member value as a hint to avoid switching the platform to an idle state unless the platform is likely to remain in this state for at least the amount of time specified by **BreakEvenDuration**.

## Remarks

The *Update* parameter of the [UpdatePlatformIdleState](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackupdateplatformidlestate) routine is a pointer to a **PEP_PLATFORM_IDLE_STATE_UPDATE** structure.

## See also

[UpdatePlatformIdleState](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackupdateplatformidlestate)