# ILocator::get_OuterFECRate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_OuterFECRate** method gets the outer FEC rate.

## Parameters

### `FEC` [out]

Pointer to a variable of type [BinaryConvolutionCodeRate](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/binaryconvolutioncoderate) that receives the outer FEC rate.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator)

[get_InnerFECRate](https://learn.microsoft.com/previous-versions/dd693581(v=vs.85))

[get_OuterFEC](https://learn.microsoft.com/previous-versions/dd693582(v=vs.85))

[put_OuterFECRate](https://learn.microsoft.com/previous-versions/dd693588(v=vs.85))