# ITuner::put_TuneRequest

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_TuneRequest** method sets the tune request currently in effect for the Network Provider.

## Parameters

### `TuneRequest` [in]

Pointer to an [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) object that will be used to set the Network Provider.

## Return value

When the method is successful, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method initiates a tuning operation based on the properties of the tune request. The tuning operation may be asynchronously attempted.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituner)