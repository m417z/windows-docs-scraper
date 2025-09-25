# _KSCLOCK_DISPATCH structure

## Description

The KSCLOCK_DISPATCH structure contains the callbacks required for a pin to implement a clock object.

## Members

### `SetTimer`

Optionally contains a pointer to an alternate function to use in generating DPC timer callbacks based on a presentation time. If this is set, this function is used to set timers based on deltas to the current presentation time in order to generate event notifications. If an alternate function is specified to set timers, a corresponding **CancelTimer** function must also be provided. This is set to **NULL** if the default [KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex) function is used to approximate the next notification time. This would normally be set only if a **KeSetTimerEx** function was being used. The function must have the same characteristics as the default function.

The function should be prototyped as follows:

```cpp
BOOLEAN SetTimer (IN PKSPIN Pin,
    IN PKTIMER Timer,
    IN LARGE_INTEGER DueTime,
    IN PKDPC Dpc);
```

See the documentation for **KeSetTimerEx** for details on implementation of this function. Any client implementation must behave in a similar manner.

### `CancelTimer`

Optionally contains an alternate function to use in canceling outstanding timer callbacks. If an alternate function is provided to cancel timers, a corresponding *SetTimer* function must also be provided. This is set to **NULL** if the default **KeCancelTimer** function is to be used. The function must have the same characteristics as the default function.

The function should be prototyped as follows:
```cpp
BOOLEAN CancelTimer (IN PKSPIN Pin,
    IN PKTIMER Timer);
```

See the documentation for **KeCancelTimer** for details on the implementation of this function. Any client implementation must behave in a similar manner.

### `CorrelatedTime`

A pointer to a function to retrieve the current clock time and a correlated system time as an atomic operation. The function should be prototyped as follows:

```cpp
LONGLONG CorrelatedTime (IN PKSPIN Pin,
    OUT PLONGLONG SystemTime);
```

The current clock time should be returned and the current system time should be placed in **SystemTime**.

### `Resolution`

A pointer to a function to specify the resolution of the clock. This corresponds to the KS property [KSPROPERTY_CLOCK_RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-resolution). This function should report the granularity in terms of 100-nanosecond units. For more information, see the KS documentation on KSPROPERTY_CLOCK_RESOLUTION.

The function should be prototyped as follows:

```cpp
void Resolution (IN PKSPIN Pin,
        OUT PKSRESOLUTION Resolution);
```

## See also

[KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)

[KSPROPERTY_CLOCK_RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-clock-resolution)

[KSRESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksresolution)

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)