# IDrmPort::DestroyContent

## Description

The DestroyContent method deletes a DRM content ID that was created by IDrmPort::CreateContentMixed. Note that this method is identical in operation to the [DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId`

Specifies a nonzero DRM content ID assigned to a KS audio stream by DrmCreateContentMixed. Note that a content ID of zero represents an audio stream with default DRM content rights, and cannot be used with this function.

## Return value

This method returns NTSTATUS - STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

See comments in [DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent).

## See also

[IDrmPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idrmport)