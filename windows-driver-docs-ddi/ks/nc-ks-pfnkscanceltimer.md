# PFNKSCANCELTIMER callback function

## Description

A streaming minidriver's *KStrCancelTimer* routine is called to cancel a custom timer object that was previously specified in the *SetTimer* parameter in a call to [KsAllocateDefaultClockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclockex).

## Parameters

### `Context` [in]

Pointer to the minidriver-supplied information context. The minidriver passes the information context to [KsAllocateDefaultClockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclockex) in the function's *DeferredContext* parameter when the minidriver allocates a custom DPC timer object.

### `Timer` [in]

Pointer to the minidriver's custom timer object to cancel.

## Return value

Returns **TRUE** if the specified timer object is in the system timer queue, or **FALSE** otherwise.

## Remarks

Minidrivers can optionally supply a *KStrCancelTimer* callback function as a parameter to **KsAllocateDefaultClockEx**.

The minidriver-supplied *KStrCancelTimer* must have the same characteristics as [KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer).

If a minidriver supplies a *KStrCancelTimer* callback function, the minidriver must also supply a [KStrSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkssettimer) callback function.

## See also

[KStrSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkssettimer)

[KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer)

[KsAllocateDefaultClockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclockex)