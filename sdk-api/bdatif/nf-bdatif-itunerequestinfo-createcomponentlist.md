# ITuneRequestInfo::CreateComponentList

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **CreateComponentList** method creates a new [Components](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/components-object) collection for the tune request, and fills it in with all network-specific data after the receiver has tuned to the service.

## Parameters

### `CurrentRequest` [in]

Pointer to the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface on the tune request.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded and new data was added. |
| **S_FALSE** | The method succeeded but no new data was added. |
| **E_FAIL** | No data could be acquired. |

## Remarks

After the Network Provider has acquired the correct transport stream, it asks the TIF to fill in the component data. If the tune request does not already have a components list, the Network Provider calls this method and asks the TIF to create one based on the relevant transport stream tables. Generally, the components will include one or more audio streams, video, data, and text. Each component has a component type, and on MPEG2 tuning spaces each component has an associated PID and pcrPID. Ideally, when the Guide Store Loader creates tune requests, it will include all the component information that is available.

The [ITuneRequestInfo::GetComponentData](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-itunerequestinfo-getcomponentdata) method is used to enable the TIF to change an existing list of components. S_FALSE indicates nothing was changed.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuneRequestInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-itunerequestinfo)