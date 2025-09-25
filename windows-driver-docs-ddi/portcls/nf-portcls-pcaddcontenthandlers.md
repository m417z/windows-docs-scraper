# PcAddContentHandlers function

## Description

The **PcAddContentHandlers** function provides the system with a list of functions that handle protected content. Note that this function call is identical in operation to the [DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `paHandlers` [in]

Pointer to an array of function pointers. Each array element points to a content handler.

### `NumHandlers` [in]

Specifies the number of function pointers in the *paHandlers* array.

## Return value

See return value definition in [DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers).

## Remarks

For more information, see the comments in [DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers).

## See also

[DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers)