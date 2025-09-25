# IMPEG2TuneRequestFactory::CreateTuneRequest

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **CreateTuneRequest** method creates the minimal MPEG-2 tune request for a specified tuning space.

## Parameters

### `TuningSpace` [in]

Pointer to the [ITuningSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace) interface of the tuning space.

### `TuneRequest` [out]

Address of a variable that receives a pointer to the [IMPEG2TuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-impeg2tunerequest) interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IMPEG2TuneRequestFactory Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-impeg2tunerequestfactory)