# IDVBTLocator::put_LPInnerFECRate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_LPInnerFECRate** method sets the inner FEC rate of the low-priority stream.

## Parameters

### `FEC` [in]

Variable of type [BinaryConvolutionCodeRate](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/binaryconvolutioncoderate) that specifies the rate.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IDVBTLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-idvbtlocator)