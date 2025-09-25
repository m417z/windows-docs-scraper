# ITuneRequestInfo::GetComponentData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetComponentData** method fills in all network-specific component data for the existing [Components](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/components-object) collection on the specified tune request.

## Parameters

### `CurrentRequest` [in]

Pointer to the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface on the tune request.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded and new data was added. |
| **S_FALSE** | The method succeeded but no new data was added. |

## Remarks

The Network Provider calls this method after the tuner has tuned to the specified service.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuneRequestInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-itunerequestinfo)