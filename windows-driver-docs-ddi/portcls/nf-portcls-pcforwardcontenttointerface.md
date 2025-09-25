# PcForwardContentToInterface function

## Description

The **PcForwardContentToInterface** function accepts a pointer to the COM interface of an object to which the caller intends to forward protected content. Note that this function call is identical in operation to the [DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `pUnknown` [in]

Pointer to a COM interface that directly receives KS audio stream data for a KS audio filter.

### `NumMethods` [in]

Specifies the total number of methods in the COM interface that *pUnknown* points to, including all the methods in its base interfaces.

## Return value

See return value definition in [DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface).

## Remarks

For more information, see the comments in [DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface).

## See also

[DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface)