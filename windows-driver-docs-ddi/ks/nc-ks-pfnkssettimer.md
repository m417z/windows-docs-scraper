# PFNKSSETTIMER callback function

## Description

A streaming minidriver's *KStrSetTimer* routine is called to generate DPC timer callbacks based on presentation time.

## Parameters

### `Context` [in]

Pointer to the minidriver-supplied information context. The minidriver passes the information context to [KsAllocateDefaultClockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclockex) in the function's *DeferredContext* parameter when the minidriver allocates a custom DPC timer object.

### `Timer` [in]

Pointer to a timer object allocated by the minidriver.

### `DueTime` [in]

Specifies the absolute or relative time at which the timer is to expire. If the value of the *DueTime* parameter is negative, the expiration time is relative to the current system time. Otherwise, the expiration time is absolute. The expiration time is expressed in system time units (100-nanosecond intervals). Absolute expiration times track any changes in the system time; relative expiration times are not affected by system time changes.

### `Dpc` [in]

Pointer to a DPC object that the minidriver initialized using [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc). This parameter is optional.

## Return value

Returns **TRUE** if the timer object was already in the system timer queue. Otherwise, returns **FALSE**.

## Remarks

Minidrivers can optionally supply a *KStrSetTimer* callback function as an argument to [KsAllocateDefaultClockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclockex).

Typically, if a minidriver supplies a *KStrCorrelatedTime* callback function, then the minidriver also supplies a *KStrSetTimer* callback function.

If minidrivers supply a *KStrSetTimer* callback function, the function must set timers, based on deltas, to the current presentation time in order to generate event notifications.

If a minidriver supplies a *KStrSetTimer* callback function, the minidriver must also supply a [KStrCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscanceltimer) callback function to cancel the timer.

The minidriver supplied *KStrSetTimer* must have the same characteristics as [KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex).

## See also

[KStrCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscanceltimer)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)

[KsAllocateDefaultClockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclockex)