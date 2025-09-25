# ILocator::get_Modulation

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Modulation** method gets the modulation type.

## Parameters

### `Modulation` [out]

Receives the modulation type, as a member of the [ModulationType](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/modulationtype) enumeration.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

See [put_Modulation](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ilocator-put_modulation) for the definition of **ModulationType**.

## See also

[ILocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ilocator)