# ITuner::get_SignalStrength

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SignalStrength** method retrieves the Network Provider-specific signal strength metric.

## Parameters

### `Strength` [out]

Receives the signal strength.

## Return value

When the method is successful, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

The value -1 means can't determine, 0 means not tuned, highest value means best signal. For digital tuners, this also accounts for the FEC bit error rate (BER).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituner)