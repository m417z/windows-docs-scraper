# ILocator::get_SymbolRate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SymbolRate** method gets the QPSK symbol rate.

## Parameters

### `Rate` [out]

Receives the QPSK symbol rate. The rate is expressed in symbols per second.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ILocator](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator)

[put_SymbolRate](https://learn.microsoft.com/previous-versions/dd693589(v=vs.85))