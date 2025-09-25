## Description

The **AcxTargetStreamAssignDrmContentId** function given an existing ACXTARGETSTREAM object, assigns a DRM Content ID to that stream.

## Parameters

### `TargetStream`

An existing ACXTARGETSTREAM object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ContentId`

Specifies the DRM content ID. This parameter is an identifier that the DRM system generates at run time to identify DRM-protected content in this stream.

### `DrmRights`

Pointer to a DRMRIGHTS structure specifying the rights granted by the content provider to the user for playing and copying DRM-protected content in this stream.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)