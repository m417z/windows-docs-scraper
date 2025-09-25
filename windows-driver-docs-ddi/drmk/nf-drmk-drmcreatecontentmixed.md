# DrmCreateContentMixed function

## Description

The `DrmCreateContentMixed` function creates a DRM content ID to identify a KS audio stream containing mixed content from a number of streams.

## Parameters

### `paContentId` [in]

Pointer to an array of DRM content IDs. Each array element is of type ULONG and contains a content ID that represents a protected KS audio stream. If *cContentId* is zero, *paContentID* can be **NULL**. A content ID of zero is a special value that represents an audio stream with default DRM content rights (see [DEFINE_DRMRIGHTS_DEFAULT](https://learn.microsoft.com/previous-versions/ff536254(v=vs.85))).

### `cContentId` [in]

Specifies the number of DRM content IDs in the *paContentId* array. The array can hold zero or more content IDs.

### `pMixedContentId` [out]

Output pointer for the composite content ID. This parameter points to a caller-allocated ULONG variable into which the function writes the new content ID for the composite KS audio stream. If *cContentId* is zero, the function assigns default DRM content rights to the new content ID.

## Return value

`DrmCreateContentMixed` returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

A KS audio filter calls the `DrmCreateContentMixed` function to obtain a DRM content ID for a composite stream. The filter produces this stream by mixing together the KS audio streams whose content IDs are listed in the *paContentId* array. Given this list of content IDs for the streams at the mixer inputs, the function calculates the content rights of the composite stream and assigns a new content ID to that stream.

If the caller does not specify any content IDs (that is, if *cContentId* is zero), the function assigns default content rights to the content ID that it creates to identify the composite stream.

After obtaining a content ID from `DrmCreateContentMixed`, the caller can get the content rights assigned to the content ID by calling [DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights).

After a change to the content rights of any of the components of a composite audio stream, the KS audio filter that mixes the stream must call `DrmCreateContentMixed` to obtain a new content ID for the composite audio stream. `DrmCreateContentMixed` determines the most restrictive of the content rights that are assigned to the individual content IDs specified in the *paContentId* array and assigns these rights to the new content ID.

After a KS audio filter finishes using a content ID that it created using `DrmCreateContentMixed`, the filter must call [DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent) to delete the content ID. However, before deleting an old content ID, the KS audio filter must first successfully forward a new content ID to all the streams to which it previously forwarded the old content ID. The KS audio filter forwards a content ID by calling a **DrmForwardContentTo***Xxx* function.

`DrmCreateContentMixed` performs the same function as [PcCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pccreatecontentmixed) and [IDrmPort::CreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-createcontentmixed). For more information, see [DRM Functions and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/audio/drm-functions-and-interfaces).

## See also

[DEFINE_DRMRIGHTS_DEFAULT](https://learn.microsoft.com/previous-versions/ff536254(v=vs.85))

[DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent)

[DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject)

[DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface)

[DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights)

[IDrmPort::CreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-createcontentmixed)

[PcCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pccreatecontentmixed)