# _PEP_PPM_FEEDBACK_READ structure (pepfx.h)

## Description

The **PEP_PPM_FEEDBACK_READ** structure contains the value read from a processor performance feedback counter.

## Members

### `CounterIndex`

The zero-based index that identifies which processor performance feedback counter to read. If the platform extension plug-in (PEP) supports N counters for this processor, counter indexes range from 0 to N-1. The PEP previously supplied the number of supported counters in response to a [PEP_NOTIFY_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities) notification.

### `InstantaneousValue`

The current instantaneous value read from the counter, if the counter generates an instantaneous value.

### `NominalCount`

The nominal accumulated value of the counter. The accumulated value is the sum of all actual values that have so far been read from the counter hardware.

### `ActualCount`

The actual value read from the counter.

## Remarks

This structure is used by the **PEP_NOTIFY_PPM_FEEDBACK_READ** notification. The *CounterIndex* member of the structure contains an input value supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) when this notification is set. The other members contain output values that the PEP writes to the structure in response to the notification. The PEP writes to the *InstantaneousValue* member if the counter generates an instantaneous value, or to the *NominalCount* and *ActualCount* members if the counter generates a relative value.

Both an instantaneous counter and a relative counter are reset to zero when power is first turned on, but reading a relative counter causes the count to reset to zero, whereas reading an instantaneous counter does not reset the count. The PEP previously indicated whether the counter is instantaneous or relative in response to a [PEP_NOTIFY_PPM_QUERY_FEEDBACK_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_feedback_counters) notification.

The unnamed union contains either an instantaneous counter value, if the counter generates an instantaneous value, or both relative and accumulated counter values, if the counter hardware generates a relative value. For more information, see Remarks.

The unnamed struct contains the nominal accumulated count and actual count, if the counter hardware generates a relative value.

## See also

- [PEP_NOTIFY_PPM_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_capabilities)
- [PEP_NOTIFY_PPM_QUERY_FEEDBACK_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_feedback_counters)