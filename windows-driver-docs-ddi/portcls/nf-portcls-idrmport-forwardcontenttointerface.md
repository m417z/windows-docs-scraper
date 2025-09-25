# IDrmPort::ForwardContentToInterface

## Description

The ForwardContentToInterface method accepts a pointer to the COM interface of an object to which the caller intends to forward protected content. Note that this method is identical in operation to the [DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface) function, and its parameter definitions and return value are also identical.

## Parameters

### `ContentId`

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `pUnknown`

Pointer to a COM interface that directly receives KS audio stream data for a KS audio filter.

### `NumMethods`

Specifies the total number of methods in the COM interface that pUnknown points to, including all the methods in its base interfaces.

## Return value

This method returns NTSTATUS.

## Remarks

See comments in [DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface).

## See also

[IDrmPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idrmport)