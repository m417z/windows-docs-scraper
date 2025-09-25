# ILocator::put_InnerFECRate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_InnerFECRate** method sets the inner FEC rate.

## Parameters

### `FEC` [in]

Specifies the inner FEC rate. This parameter is a value of type [BinaryConvolutionCodeRate](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/binaryconvolutioncoderate).

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator)

[get_InnerFECRate](https://learn.microsoft.com/previous-versions/dd693581(v=vs.85))

[put_InnerFEC](https://learn.microsoft.com/previous-versions/dd693585(v=vs.85))

[put_OuterFECRate](https://learn.microsoft.com/previous-versions/dd693588(v=vs.85))