## Description

The **AcxDrmDestroyContent** function deletes a DRM content ID that was created by [AcxDrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxdrmcreatecontentmixed).

## Parameters

### `ContentId`

Specifies a nonzero DRM content ID assigned to an ACX audio stream by [AcxDrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxdrmcreatecontentmixed). Note that a content ID of zero represents an audio stream with default DRM content rights, and cannot be used with this function.

## Return value

AcxDrmDestroyContentMixed returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)