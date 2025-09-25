# IKsPin::KsPropagateAcquire

## Description

The **KsPropagateAcquire** method directs all the pins on the filter to attain the Acquire state.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

By using this method, a Communication source pin can direct the sink to which it is connected to change state before the Source. This forces the entire filter to which the sink belongs to change state so that any Acquire can be further propagated if needed.

This method is for proxy use and is not recommended for application use.

## See also

[IKsPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikspin)