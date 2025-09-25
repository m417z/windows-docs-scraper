# IDrmPort::CreateContentMixed

## Description

The CreateContentMixed method computes the DRM content rights for a composite stream containing mixed content from some number of KS audio streams. Note that this method is identical in operation to the [DrmCreateContentMixed function](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed), and its parameter definitions and return value are also identical.

## Parameters

### `paContentId`

Pointer to an array of DRM content IDs. Each array element is of type ULONG and contains a content ID that represents a protected KS audio stream. If cContentId is zero, paContentID can be NULL. A content ID of zero is a special value that represents an audio stream with default DRM content rights (see DEFINE_DRMRIGHTS_DEFAULT).

### `cContentId`

Specifies the number of DRM content IDs in the paContentId array. The array can hold zero or more content IDs.

### `pMixedContentId`

Output pointer for the composite content ID. This parameter points to a caller-allocated ULONG variable into which the function writes the new content ID for the composite KS audio stream. If cContentId is zero, the function assigns default DRM content rights to the new content ID.

## Return value

This method returns NTSTATUS - STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

A KS audio filter calls the DrmCreateContentMixed function to obtain a DRM content ID for a composite stream. The filter produces this stream by mixing together the KS audio streams whose content IDs are listed in the paContentId array. Given this list of content IDs for the streams at the mixer inputs, the function calculates the content rights of the composite stream and assigns a new content ID to that stream.

If the caller does not specify any content IDs (that is, if cContentId is zero), the function assigns default content rights to the content ID that it creates to identify the composite stream.

After obtaining a content ID from DrmCreateContentMixed, the caller can get the content rights assigned to the content ID by calling DrmGetContentRights.

After a change to the content rights of any of the components of a composite audio stream, the KS audio filter that mixes the stream must call DrmCreateContentMixed to obtain a new content ID for the composite audio stream. DrmCreateContentMixed determines the most restrictive of the content rights that are assigned to the individual content IDs specified in the paContentId array and assigns these rights to the new content ID.

After a KS audio filter finishes using a content ID that it created using DrmCreateContentMixed, the filter must call DrmDestroyContent to delete the content ID. However, before deleting an old content ID, the KS audio filter must first successfully forward a new content ID to all the streams to which it previously forwarded the old content ID. The KS audio filter forwards a content ID by calling a DrmForwardContentToXxx function.

DrmCreateContentMixed performs the same function as PcCreateContentMixed and IDrmPort::CreateContentMixed.

## See also

[IDrmPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idrmport)