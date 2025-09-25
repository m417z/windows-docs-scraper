## Description

The **ExEnterCriticalRegionAndAcquireResourceExclusive** routine first enters a critical region, and then acquires exclusive access to the specified resource.

## Parameters

### `Resource`

[in, out] A pointer to the resource to acquire for exclusive access. This parameter points to a caller-allocated [**ERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines) structure. The caller previously allocated this structure from nonpaged pool and initialized it by calling the [**ExInitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite) or [**ExReinitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite) routine.

## Return value

A pointer to an opaque system structure. Drivers should ignore this return value.

## Remarks

If this routine is called when the specified resource is not immediately available for exclusive access, the calling thread is blocked until the resource is available.

While a driver thread runs in the critical region, the driver's user APCs and normal kernel APCs are not executed. Special kernel APCs are still executed. For more information about these APC types, see [Types of APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-apcs).

By temporarily disabling normal kernel APCs, **ExEnterCriticalRegionAndAcquireResourceExclusive** prevents a passive-level calling thread from being preempted by an APC while the thread holds a shared resource that the APC might try to access.

The calling thread should stay in the critical region and hold the specified resource for no longer than is necessary. To release the specified resource and leave the critical region, call the [**ExReleaseResourceAndLeaveCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourceandleavecriticalregion) routine.

For more information about using an [**ERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines) structure to synchronize exclusive access to a resource, see [Introduction to ERESOURCE Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines). For more information about entering and leaving a critical region, see [Critical Regions and Guarded Regions](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

## See also

[**ERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines)

[**ExAcquireResourceExclusiveLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquireresourceexclusivelite)

[**ExInitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite)

[**ExReinitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite)

[**ExReleaseResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite)

[**ExReleaseResourceAndLeaveCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourceandleavecriticalregion)

[**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keentercriticalregion)

[**KeLeaveCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keleavecriticalregion)