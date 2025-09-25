# _PEP_PPM_QUERY_CAPABILITIES structure (pep_x.h)

## Description

The **PEP_PPM_QUERY_CAPABILITIES** structure contains information about the processor power management (PPM) capabilities of the platform extension plug-in (PEP).

## Members

### `FeedbackCounterCount`

The number of processor performance feedback counters supported by the PEP for this processor. On x86/AMD64 platforms, this must be zero.

### `IdleStateCount`

The number of processor idle states that the PEP supports. The PEP is not required to support the same number of idle states for all processors. The PEP can set `IdleStateCount = 0` to indicate that it doesn't support any idle states, in which case the PEP doesn't need to implement any other notifications that deal with processor idle states.

### `PerformanceStatesSupported`

Whether the PEP supports performance state controls. Set to TRUE if the PEP supports performance states, or to FALSE if it does not.

### `ParkingSupported`

Whether the PEP supports supplying core parking hints. Set to TRUE if the PEP can indicate which cores to park, or to FALSE if it cannot.

### `DiscretePerformanceStateCount`

The number of discrete performance states that the PEP supports.

### `Reserved`

Reserved for future use. Set to zero.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities) notification. All four members contain output values that the PEP writes to the structure in response to this notification.

## See also

- [PEP_NOTIFY_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities)