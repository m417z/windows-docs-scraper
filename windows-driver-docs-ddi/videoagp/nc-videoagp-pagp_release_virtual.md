# PAGP_RELEASE_VIRTUAL callback function

## Description

The **AgpReleaseVirtual** function frees system memory reserved by a previous call to [AgpReserveVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_virtual).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `VirtualReserveContext` [in]

Is the context handle that identifies the reserved virtual address range to be released. This context was obtained from **AgpReleaseVirtual**.

## Remarks

The miniport driver must call [AgpFreeVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_free_virtual) to unmap all committed memory within the range identified by **VirtualReserveContext** before calling **AgpReleaseVirtual** to release it.

## See also

[AgpFreePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_free_physical)

[AgpReservePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical)