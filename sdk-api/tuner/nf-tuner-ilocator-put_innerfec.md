# ILocator::put_InnerFEC

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_InnerFEC** method sets the type of inner FEC to use.

## Parameters

### `FEC` [in]

Specifies the inner FEC. This parameter is a value of type [FECMethod](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/fecmethod).

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator)

[get_InnerFEC](https://learn.microsoft.com/previous-versions/dd693580(v=vs.85))

[put_InnerFECRate](https://learn.microsoft.com/previous-versions/dd693586(v=vs.85))

[put_OuterFEC](https://learn.microsoft.com/previous-versions/dd693587(v=vs.85))