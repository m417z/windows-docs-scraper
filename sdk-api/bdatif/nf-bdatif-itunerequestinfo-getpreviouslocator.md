# ITuneRequestInfo::GetPreviousLocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetPreviousLocator** method creates a new tune request with locator information for the previous transport stream.

## Parameters

### `CurrentRequest` [in]

Specifies current request.

### `TuneRequest` [out]

Pointer to a variable that receives the tune request for the previous transport stream in the network.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *CurrentRequest* is not valid, or *TuneRequest* is **NULL**. |

## Remarks

Currently this method is not implemented for DVB-C or DVB-S networks, and the method returns E_NOTIMPL. The method is implemented for DVB-T.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuneRequestInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-itunerequestinfo)