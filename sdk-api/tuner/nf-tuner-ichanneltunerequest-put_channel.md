# IChannelTuneRequest::put_Channel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Channel** method sets the channel to be tuned.

## Parameters

### `Channel` [in]

Variable of type **long** that specifies the channel.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM IErrorInfo interface.

## Remarks

If the value specified for *Channel* is less than the minimum channel set for the tuning space, it will "wrap around" to the maximum channel value. Likewise, if the value specified for *Channel* is greater than the maximum channel set for the tuning space, it will "wrap around" to the minimum channel value.

## See also

[IChannelTuneRequest Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ichanneltunerequest)