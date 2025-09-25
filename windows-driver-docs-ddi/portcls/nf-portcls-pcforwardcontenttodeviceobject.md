# PcForwardContentToDeviceObject function

## Description

The **PcForwardContentToDeviceObject** function accepts a device object representing a device to which the caller intends to forward protected content. Note that this function call is identical in operation to the [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `Reserved` [in, optional]

Reserved for future use. Set to **NULL**.

### `DrmForward` [in]

Pointer to a [DRMFORWARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmforward) structure specifying a device object and file object that identify the target device and a KS audio pin on that device, respectively. The structure also contains the context value that the [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))set-property request passes to the device.

## Return value

See return value definition in [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject).

## Remarks

For more information, see the comments in [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject).

## See also

[DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject)