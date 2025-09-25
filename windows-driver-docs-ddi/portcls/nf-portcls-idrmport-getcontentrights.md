# IDrmPort::GetContentRights

## Description

The GetContentRights method retrieves the DRM content rights that are assigned to a stream that is identified by a content ID. Note that this method is identical in operation to the [DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId`

Specifies the DRM content ID. This parameter identifies a KS audio stream.

### `DrmRights`

Specifies the DRM content rights that are assigned to the stream that is identified by ContentId. This parameter is a pointer to a DRMRIGHTS structure.

## Return value

This method returns NTSTATUS.

## Remarks

See comments in [DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights).

## See also

[IDrmPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idrmport)