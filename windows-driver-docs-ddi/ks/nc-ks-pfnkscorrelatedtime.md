# PFNKSCORRELATEDTIME callback function

## Description

A streaming minidriver's *KStrCorrelatedTime* routine is called to retrieve both the presentation time and physical time in a correlated manner. This allows the clock owner to completely determine the current time.

## Parameters

### `Context` [in]

Pointer to the minidriver-supplied information context. The minidriver passes the information context to [KsAllocateDefaultClockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclockex) in the function's *DeferredContext* parameter when the minidriver allocates a custom DPC timer object.

### `SystemTime` [out]

Specifies a pointer to a variable that receives the performance counter frequency.

## Return value

Returns the value of the performance counter in units of ticks.

## Remarks

Typically, if a minidriver supplies a *KStrCorrelatedTime* callback function, the minidriver must also supply [KStrSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkssettimer) and [KStrCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscanceltimer) callback functions.

The minidriver-supplied *KStrCorrelatedTimer* must have the same characteristics as [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter).

## See also

[KStrCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscanceltimer)

[KStrCorrelatedTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscorrelatedtime)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)

[KsAllocateDefaultClockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclockex)