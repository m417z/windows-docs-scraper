# ITuner::get_TuningSpace

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_TuningSpace** method gets the tuning space currently in effect for the Network Provider.

## Parameters

### `TuningSpace` [out]

Address of an [ITuningSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace) interface pointer that will be set to the current tuning space.

## Return value

When the method is successful, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituner)