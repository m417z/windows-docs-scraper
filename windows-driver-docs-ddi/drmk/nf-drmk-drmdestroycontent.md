# DrmDestroyContent function

## Description

The `DrmDestroyContent` function deletes a DRM content ID that was created by [DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed).

## Parameters

### `ContentId` [in]

Specifies a nonzero DRM content ID assigned to a KS audio stream by **DrmCreateContentMixed**. Note that a content ID of zero represents an audio stream with default DRM content rights, and cannot be used with this function.

## Return value

**DrmCreateContentMixed** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

A KS audio filter can only use `DrmDestroyContent` to delete a DRM content ID that it obtained by calling [DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed). Note that a KS audio filter must not use `DrmDestroyContent` to delete a DRM content ID set by [IDrmAudioStream::SetContentId](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-idrmaudiostream-setcontentid) or by an IOCTL_KS_PROPERTY request that sets the [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85)) property. Only the KS audio filter that created the content ID should delete it.

`DrmDestroyContent` performs the same function as [PcDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcdestroycontent) and [IDrmPort::DestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-destroycontent). For more information, see [DRM Functions and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/audio/drm-functions-and-interfaces).

## See also

[DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed)

[DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights)

[IDrmAudioStream::SetContentId](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-idrmaudiostream-setcontentid)

[IDrmPort::DestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-destroycontent)

[KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))

[PcDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcdestroycontent)