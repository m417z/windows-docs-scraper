## Description

The **ExReleaseResourceAndLeaveCriticalRegion** routine first releases the specified resource, and then leaves the critical region.

## Parameters

### `Resource`

[in, out] A pointer to the resource to release. This parameter should be the same [**ERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines) pointer that the caller supplied as a parameter in the previous call to the [**ExEnterCriticalRegionAndAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exentercriticalregionandacquireresourceexclusive) routine that acquired the resource.

## Remarks

After a driver calls the [**ExEnterCriticalRegionAndAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exentercriticalregionandacquireresourceexclusive) method to enter a critical region and acquire a resource for exclusive access, the driver must call **ExReleaseResourceAndLeaveCriticalRegion** to release the resource and exit the critical region.

For more information about using an **ERESOURCE** structure to synchronize exclusive access to a resource, see [Introduction to ERESOURCE Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines). For more information about entering and leaving a critical region, see [Critical Regions and Guarded Regions](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

## See also

[**ERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines)

[**ExEnterCriticalRegionAndAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exentercriticalregionandacquireresourceexclusive)