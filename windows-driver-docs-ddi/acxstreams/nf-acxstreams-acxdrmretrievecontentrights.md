## Description

The **AcxDrmRetrieveContentRights** function gets the DRM content rights assigned to a DRM content ID.

## Parameters

### `ContentId`

Specifies a nonzero DRM content ID assigned to an ACX audio stream by [AcxDrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxdrmcreatecontentmixed). A content ID of zero represents an audio stream with default DRM content rights and cannot be used with this function.

### `DrmRights`

Specifies the DRM content rights that are assigned to the stream that is identified by *ContentId*. This parameter is a pointer to an [ACXDRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acxdrmrights) structure.

## Return value

**AcxDrmRetrieveContentRights** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.1

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)