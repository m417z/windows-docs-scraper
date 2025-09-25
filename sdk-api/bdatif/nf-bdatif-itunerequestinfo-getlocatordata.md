# ITuneRequestInfo::GetLocatorData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetLocatorData** method fills in channel or program locator information for the specified tune request.

## Parameters

### `Request` [in]

Pointer to the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface on the tune request.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded and new locator data was acquired. |
| **S_FALSE** | The method succeeded but no new locator data was acquired. |
| **E_POINTER** | *Request* is not valid. |

## Remarks

After the TIF fills in the locator information, the Network Provider uses that information to configure the tuner and demodulator. It is expected that the TIF will always know everything about a locator. If it doesn't know how to locate a specific tune request, it can always fall back to the default locator for the tuning space. As soon as the TIF starts getting tables from the default stream, it signals the Network Provider, which then asks for the new locator data. When the TIF fills that in, it signals the Network Provider, which tunes again using the new information. When the TIF begins getting tables on the new stream, it signals the Network Provider again, and the process is repeated.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuneRequestInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-itunerequestinfo)