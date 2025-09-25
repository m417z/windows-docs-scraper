# DrmGetContentRights function

## Description

The `DrmGetContentRights` function retrieves the DRM content rights assigned to a DRM content ID.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a KS audio stream.

### `DrmRights` [out]

Specifies the DRM content rights that are assigned to the stream that is identified by *ContentId*. This parameter is a pointer to a [DRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmrights) structure.

## Return value

`DrmGetContentRights` returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

Before a KS audio filter begins mixing together several KS audio streams, it first calls [DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed) to create a content ID for the composite stream. Next, it calls `DrmGetContentRights` to get the content rights that the system has assigned to the stream.

A module that lies downstream from the KS filter that creates the content ID typically does not need to call `DrmGetContentRights`. Instead, the module receives both the content ID and content rights either from the system (through an [IDrmAudioStream::SetContentId](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-idrmaudiostream-setcontentid) call or a [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))set-property request) or directly from the preceding module in the data path (through a call to a content handler). For more information, see [DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface), [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject), and [DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers).

`DrmGetContentRights` performs the same function as [PcGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcgetcontentrights) and [IDrmPort::GetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-getcontentrights). For more information, see [DRM Functions and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/audio/drm-functions-and-interfaces).

## See also

[DRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmrights)

[DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers)

[DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed)

[DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject)

[DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface)

[IDrmAudioStream::SetContentId](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-idrmaudiostream-setcontentid)

[IDrmPort::GetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-getcontentrights)

[KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))

[PcGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcgetcontentrights)