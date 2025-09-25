## Description

The **AcxDrmForwardContentToDeviceObject** function accepts a device object representing a device to which the caller intends to forward protected content. The function authenticates the device and sends it the content ID and DRM rights that the system has assigned to the protected content.

## Parameters

### `ContentId`

Specifies a nonzero DRM content ID assigned to an ACX audio stream by [AcxDrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxdrmcreatecontentmixed). Note that a content ID of zero represents an audio stream with default DRM content rights, and cannot be used with this function.

### `Reserved`

Reserved for future use. Set to NULL.

### `DrmForward`

Pointer to an [ACXDRMFORWARD structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acxdrmforward) specifying a device object and file object that identify the target device and a KS audio pin on that device, respectively. The structure also contains the context value that the [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-ksp_drmaudiostream_contentid) set-property request passes to the device.

## Return value

AcxDrmForwardContentToDeviceObject returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)