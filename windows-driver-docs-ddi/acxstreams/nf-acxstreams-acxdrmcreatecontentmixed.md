## Description

The **AcxCreateContentMixed** function creates a DRM content ID to identify an ACX audio stream containing mixed content from a number of streams

## Parameters

### `paContentId`

Pointer to an array of DRM content IDs. Each array element is of type ULONG and contains a content ID that represents a protected ACX audio stream. If cContentId is zero, paContentID can be NULL. A content ID of zero is a special value that represents an audio stream with default DRM content rights (see DEFINE_DRMRIGHTS_DEFAULT).

### `cContentId`

Specifies the number of DRM content IDs in the paContentId array. The array can hold zero or more content IDs.

### `pMixedContentId`

Output pointer for the composite content ID. This parameter points to a caller-allocated ULONG variable into which the function writes the new content ID for the composite ACX audio stream. If cContentId is zero, the function assigns default DRM content rights to the new content ID.

## Return value

AcxDrmCreateContentMixed returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxDrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxdrmdestroycontent)
- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)