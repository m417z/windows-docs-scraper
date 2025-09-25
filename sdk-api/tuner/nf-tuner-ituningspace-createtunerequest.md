# ITuningSpace::CreateTuneRequest

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **CreateTuneRequest** method creates an empty (uninitialized) tune request.

## Parameters

### `TuneRequest` [out]

Address of a variable that receives a pointer to the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface of the new tune request object. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

You can query the returned **ITuneRequest** pointer for derived interfaces. For more information, see the reference pages for the individual tuning space objects, which are listed in the topic [Tuning Model Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/tuning-model-objects).

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)