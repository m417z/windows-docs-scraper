# IDrmPort::ForwardContentToFileObject

## Description

The ForwardContentToFileObject method is obsolete and is maintained only to support existing drivers. Note that this method is identical in operation to the [DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId`

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `FileObject`

Pointer to a file object that represents the KS audio pin to which the KS audio stream is sent.

## Return value

This method returns NTSTATUS - STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code. STATUS_NOT_IMPLEMENTED indicates that the KS audio pin that is associated with FileObject does not support the DRM content rights that are assigned to ContentId.

## Remarks

See comments in [DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject).

## See also

[IDrmPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idrmport)