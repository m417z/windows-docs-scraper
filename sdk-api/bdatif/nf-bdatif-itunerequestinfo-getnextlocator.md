# ITuneRequestInfo::GetNextLocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetNextLocator** method creates a new tune request with locator information for the next transport stream on the network.

## Parameters

### `CurrentRequest` [in]

Specifies the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface of the current tune request. **NULL** means to return information for the first stream.

### `TuneRequest` [out]

Pointer to a variable that receives a tune request for the next transport stream.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *CurrentRequest* is not valid, or *TuneRequest* is **NULL**. |

## Remarks

This method is used internally by the Network Provider's [IScanningTuner::SeekUp](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-iscanningtuner-seekup) and [IScanningTuner::SeekDown](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-iscanningtuner-seekdown) methods, and is also useful for any Guide Store Loader that scans a network for EPG information.

Currently this method is not implemented for DVB-C or DVB-S networks, and the method returns E_NOTIMPL. The method is implemented for DVB-T.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuneRequestInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-itunerequestinfo)