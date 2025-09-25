# VideoPortFreeDeviceBase function

## Description

The **VideoPortFreeDeviceBase** function frees a range of bus-relative device I/O ports or memory addresses previously mapped into the system address space. It does this by calling [VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase).

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `MappedAddress`

Specifies the base address of the mapped range to be freed. This value must be the same as the value returned by a preceding call to **VideoPortGetDeviceBase**.

## Return value

None

## Remarks

**VideoPortFreeDeviceBase** must be called from the miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function if the miniport driver has already mapped an address range for an adapter it cannot support or does not use any longer.

When this occurs, the miniport driver also must release its claim on the corresponding hardware resources in the registry. To release all claims on resources for a particular adapter, call [VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges) or [VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges) with the *NumAccessRanges* parameter set to zero. To release claims on selected access ranges, do the following:

1. Modify the access ranges array of claimed bus-relative ranges for the adapter by setting the appropriate elements' **RangeLength**(s) to zero. Leave the current specification as is in all elements on which the miniport driver will not release its claims.
2. Call [VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges) with this modified *AccessRanges* array.

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges)