# ILocator::get_OuterFEC

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_OuterFEC** method gets the type of outer FEC that is used.

## Parameters

### `FEC` [out]

Pointer to a variable of type [FECMethod](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/fecmethod) that receives the type of outer FEC.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator)

[get_InnerFEC](https://learn.microsoft.com/previous-versions/dd693580(v=vs.85))

[get_OuterFECRate](https://learn.microsoft.com/previous-versions/dd693583(v=vs.85))

[put_OuterFEC](https://learn.microsoft.com/previous-versions/dd693587(v=vs.85))