# KsAllocateDefaultClockEx function

## Description

The **KsAllocateDefaultClockEx** function allocates and initializes the default clock structure.

## Parameters

### `DefaultClock` [out]

Specifies the caller-allocated shared default clock structure. The current time is set to zero and the state is set to KSSTATE_STOP. Upon successful completion of this routine, the structure indicated by this pointer will contain a reference to the default clock. The data returned should be treated as opaque and reserved for system use.

### `Context` [in, optional]

Optionally contains the context of the alternate time facilities. This must be set if a timer or correlated time function is used.

### `SetTimer` [in, optional]

Optionally contains a pointer to a driver-defined [KStrSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkssettimer) function to use to generate DPC timer callbacks based on a Presentation Time. If this is set, the function will be used to set timers based on deltas to the current Presentation Time in order to generate event notifications. If you supply a *KStrSetTimer* function to set timers, you must also supply a corresponding [KStrCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscanceltimer) function. Pass **NULL** in this parameter if the default [KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex) function is to be used to approximate the next notification time. This parameter would normally be set only if a [KStrCorrelatedTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscorrelatedtime) function was also being used. The *KStrSetTimer* function must have the same characteristics as **KeSetTimerEx**.

### `CancelTimer` [in, optional]

Optionally contains a pointer to a driver-defined [KStrCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscanceltimer) function to use to cancel outstanding timer callbacks. If you supply a *KStrCancelTimer* function to cancel timers, you must also supply a corresponding [KStrSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkssettimer) function. Pass **NULL** in this parameter if the default [KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer) function is to be used to cancel timers. The *KStrCancelTimer* function must have the same characteristics as **KeCancelTimer**.

### `CorrelatedTime` [in, optional]

Optionally contains a pointer to a driver-defined [KStrCorrelatedTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscorrelatedtime) function to retrieve both the Presentation and Physical Time in a correlated manner. This allows the clock owner to completely determine the current time. Pass **NULL** if the default [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter) function is to be used to regulate time progression.

### `Resolution` [in, optional]

Optionally contains an alternate Granularity and/or Error factor for the clock. This can only be used only if an alternate timer or correlated time function are being provided. An alternate Granularity may be specified if an alternate correlated time is being used, else the structure element must be zero. An alternate Error may be specified if an alternate timer is being used, else the structure element must be zero.

### `Flags` [in]

Reserved, set to zero.

## Return value

The **KsAllocateDefaultClockEx** function returns STATUS_SUCCESS if successful, or a memory error if unsuccessful.

## Remarks

The internal DefaultClock.ReferenceCount element is initialized to one by the [KsAllocateDefaultClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclock) function. The element is incremented and decremented as each notification DPC is queued and completed. When the structure is to be freed, the element is used to determine if the owner of the clock should free the structure or if a pending DPC should free it asynchronously.

## See also

[KStrCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscanceltimer)

[KStrCorrelatedTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkscorrelatedtime)

[KStrSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkssettimer)

[KsAllocateDefaultClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclock)

[KsFreeDefaultClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreedefaultclock)