# IKsInterfaceHandler::KsSetPin

## Description

The **KsSetPin** method informs the streaming interface handler about the pin with which to communicate when passing data.

## Parameters

### `KsPin` [in]

Pointer to the [IKsPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikspin) interface for the pin to which this streaming interface handler is to be attached. This pin must support the [IKsObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksobject) interface from which the underlying kernel handle can be obtained.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The **KsSetPin** method is called after an instance of the interface handler is created but before any streaming is required of the instance.

## See also

[IKsObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksobject)

[IKsPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikspin)