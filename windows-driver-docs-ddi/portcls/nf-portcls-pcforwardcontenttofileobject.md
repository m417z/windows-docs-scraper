# PcForwardContentToFileObject function

## Description

The **PcForwardContentToFileObject** function is obsolete and is maintained only to support existing drivers. Note that this function call is identical in operation to the [DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `FileObject` [in]

Pointer to a file object that represents the KS audio pin to which the KS audio stream is sent.

## Return value

See return value definition in [DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject).

## Remarks

For more information, see the comments in [DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject).

## See also

[DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject)