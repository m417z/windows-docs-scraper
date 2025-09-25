# PAGP_RELEASE_PHYSICAL callback function

## Description

The **AgpReleasePhysical** function frees a physical address range reserved by a previous call to [AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `PhysicalReserveContext` [in]

Is the context handle that identifies the reserved physical address range to be released. This context was obtained from [AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical).

## Remarks

The miniport driver must call [AgpFreePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_free_physical) to unmap all committed memory within the address range identified by **PhysicalReserveContext** before calling **AgpReleasePhysical**.

## See also

[AgpFreePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_free_physical)

[AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical)