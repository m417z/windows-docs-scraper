# DrmForwardContentToFileObject function

## Description

The `DrmForwardContentToFileObject` function is obsolete and is maintained only to support existing drivers. This function sends the operating system a file object representing a device that handles protected content. It also forwards to the specified device the content ID and associated DRM rights of a stream containing protected content.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `FileObject` [in]

Pointer to a file object that represents the KS audio pin to which the KS audio stream is sent.

## Return value

`DrmForwardContentToFileObject` returns STATUS_SUCCESS if the call was successful. The following table shows some of the possible error return values.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_IMPLEMENTED** | Indicates that the KS audio pin that is associated with *FileObject* does not support the DRM content rights that are assigned to *ContentId*. |

## Remarks

This function is superseded by [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject). A driver that calls `DrmForwardContentToFileObject` forces the system to run at a lower DRM security level. New drivers should call `DrmForwardContentToDeviceObject` instead.

The `DrmForwardContentToFileObject` function authenticates the KS audio filter that implements the KS audio pin represented by *FileObject*. If `DrmForwardContentToFileObject` successfully authenticates the KS audio filter, it sets the KS property [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85)) on the audio pin that is represented by *FileObject*. The property data includes a DRM content ID and a [DRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmrights) structure. `DrmForwardContentToFileObject` makes no use of *FileObject* after returning.

`DrmForwardContentToFileObject` performs the same function as [PcForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcforwardcontenttofileobject) and [IDrmPort::ForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-forwardcontenttofileobject). For more information, see [DRM Functions and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/audio/drm-functions-and-interfaces).

## See also

[DRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmrights)

[DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject)

[IDrmPort::ForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-forwardcontenttofileobject)

[KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))

[PcForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcforwardcontenttofileobject)