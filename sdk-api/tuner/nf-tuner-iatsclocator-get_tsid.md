# IATSCLocator::get_TSID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_TSID** method retrieves the transport stream ID.

## Parameters

### `TSID` [out]

Receives the transport stream ID.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This property is not required for tuning. It will be set by the BDA Transport Information Filter (TIF) when the signal is acquired. This property is not used by the application but may be used by one or more of the receiver filters. For example, a TIF may use this to determine whether the transport stream has changed from what was originally tuned and generate events that cause re-acquisition of the requested program.

## See also

[IATSCLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iatsclocator)