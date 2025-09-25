# ITuneRequestInfo::GetPreviousProgram

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetPreviousProgram** method creates a new tune request with channel or program locator information for the previous service.

## Parameters

### `CurrentRequest` [in]

Specifies the current request.

### `TuneRequest` [out]

Pointer to a variable that receives a tune request for the previous service in the current transport stream.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *CurrentRequest* is not valid, or *TuneRequest* is **NULL**. |

## Remarks

This method might be used by a custom Guide Store Loader to enumerate the available services on a transport stream.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuneRequestInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-itunerequestinfo)