# IBDACreateTuneRequestEx::CreateTuneRequestEx

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Creates a new tuning request for a tuning space. This method enables the caller to specify a particular type of tuning request.

## Parameters

### `TuneRequestIID` [in]

GUID that identifies the type of [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) object expected by the caller. If this value is **NULL**, this method behaves the same as [ITuningSpace::CreateTuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspace-createtunerequest) and creates an empty (uninitialized) **ITuneRequest** object.

### `TuneRequest` [out]

Address of a variable that receives a pointer to the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface of the new tuning request object. The caller must release the interface. If the *TuneRequestIID* argument is **NULL**, this address is set to **NULL** also.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDACreateTuneRequestEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ibdacreatetunerequestex)

[ITuningSpace::CreateTuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspace-createtunerequest)