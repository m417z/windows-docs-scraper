# ILocator::get_InnerFEC

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_InnerFEC** method gets the type of inner FEC that is used.

## Parameters

### `FEC` [out]

Pointer to a variable of type [FECMethod](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/fecmethod) that receives the type of inner FEC.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator)

[get_InnerFECRate](https://learn.microsoft.com/previous-versions/dd693581(v=vs.85))

[get_OuterFEC](https://learn.microsoft.com/previous-versions/dd693582(v=vs.85))

[put_InnerFEC](https://learn.microsoft.com/previous-versions/dd693585(v=vs.85))