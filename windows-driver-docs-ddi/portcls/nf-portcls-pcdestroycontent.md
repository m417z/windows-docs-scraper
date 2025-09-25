# PcDestroyContent function

## Description

The **PcDestroyContent** function deletes a DRM content ID that was created by [PcCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pccreatecontentmixed). Note that this function call is identical in operation to the [DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId` [in]

Specifies a nonzero DRM content ID assigned to a KS audio stream by **DrmCreateContentMixed**. Note that a content ID of zero represents an audio stream with default DRM content rights, and cannot be used with this function.

## Return value

See return value definition in [DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent).

## Remarks

For more information, see the comments in [DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent).

## See also

[DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent)

[PcCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pccreatecontentmixed)