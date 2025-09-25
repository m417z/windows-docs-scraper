# PcCreateContentMixed function

## Description

The **PcCreateContentMixed** function computes the DRM content rights for a composite stream containing mixed content from some number of KS audio streams. Note that this function call is identical in operation to the [DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed) function, and its parameter definitions and return value are also identical.

## Parameters

### `paContentId` [in]

Pointer to an array of DRM content IDs. Each array element is of type ULONG and contains a content ID that represents a protected KS audio stream. If *cContentId* is zero, *paContentID* can be **NULL**. A content ID of zero is a special value that represents an audio stream with default DRM content rights (see [DEFINE_DRMRIGHTS_DEFAULT](https://learn.microsoft.com/previous-versions/ff536254(v=vs.85))).

### `cContentId` [in]

Specifies the number of DRM content IDs in the *paContentId* array. The array can hold zero or more content IDs.

### `pMixedContentId` [out]

Output pointer for the composite content ID. This parameter points to a caller-allocated ULONG variable into which the function writes the new content ID for the composite KS audio stream. If *cContentId* is zero, the function assigns default DRM content rights to the new content ID.

## Return value

See return value definition in [DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed).

## Remarks

For more information, see the comments in [DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed).

## See also

[DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed)