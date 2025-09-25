# IDrmAudioStream::SetContentId

## Description

The `SetContentId` method sets the DRM content ID and its assigned DRM content rights on a KS audio stream.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter is an identifier that the DRM system generates at run time to identify DRM-protected content in this stream.

### `DrmRights` [in]

Pointer to a [DRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmrights) structure specifying the rights granted by the content provider to the user for playing and copying DRM-protected content in this stream.

## Return value

`SetContentId` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code. If the filter cannot enforce the specified content rights, the method returns STATUS_NOT_IMPLEMENTED.

## Remarks

The DRM system can call the `SetContentId` method at any time during the lifetime of a KS audio stream.

A KS audio filter completes the execution of a call to the `SetContentId` method synchronously. If the function returns STATUS_SUCCESS, this indicates that all the downstream KS audio nodes (see [Audio Topology Nodes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-topology-nodes)) of a KS audio stream have also been successfully configured with the specified DRM content ID and DRM content rights. (The term *downstream node* refers to either a direct or an indirect sink for an audio stream.)

If the KS audio filter cannot enforce the specified DRM content rights, the `SetContentId` method returns the error code STATUS_NOT_IMPLEMENTED. In this case, the KS audio stream's previously set DRM content ID and DRM content rights remain set on the stream.

For more information about using this method, see [Digital Rights Management](https://learn.microsoft.com/windows-hardware/drivers/audio/digital-rights-management).

## See also

[DRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmrights)

[DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed)

[DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent)

[DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject)

[DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface)

[DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights)

[IDrmAudioStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nn-drmk-idrmaudiostream)