# ILocator::get_InnerFECRate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_InnerFECRate** method gets the inner FEC rate.

## Parameters

### `FEC` [out]

Pointer to a variable of type [BinaryConvolutionCodeRate](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/binaryconvolutioncoderate) that receives the inner FEC rate.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator)

[get_InnerFEC](https://learn.microsoft.com/previous-versions/dd693580(v=vs.85))

[get_OuterFECRate](https://learn.microsoft.com/previous-versions/dd693583(v=vs.85))

[put_InnerFECRate](https://learn.microsoft.com/previous-versions/dd693586(v=vs.85))