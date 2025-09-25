# PcGetContentRights function

## Description

The **PcGetContentRights** function retrieves the DRM content rights assigned to a DRM content ID. Note that this function call is identical in operation to the [DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a KS audio stream.

### `DrmRights` [out]

Specifies the DRM content rights that are assigned to the stream that is identified by *ContentId*. This parameter is a pointer to a [DRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmrights) structure.

## Return value

See return value definition in [DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights).

## Remarks

For more information, see the comments in [DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights).

## See also

[DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights)