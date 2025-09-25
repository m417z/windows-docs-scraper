# IGuideData::GetServiceProperties

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetServiceProperties** method retrieves the properties for a specified service.

## Parameters

### `pTuneRequest` [in]

Pointer to the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface of a valid tune request. Call the [IGuideData::GetServices](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedata-getservices) method to get a list of tune requests.

### `ppEnumProperties` [out]

Pointer to a variable that receives an [IEnumGuideDataProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-ienumguidedataproperties) interface pointer. Use this interface to enumerate the properties. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The returned collection includes the following properties.

| Property | Description |
| --- | --- |
| Description.ID | The unique identifier for the service. |
| Description.Name | Default name to use for this service in the channel lineup. |
| Provider.Name | Name of the service provider. |
| Provider.NetworkName | Name of the network on which the service is provided. |

The method fails if the TIF has not received the service information from the PSI tables in the transport stream. The client should implement the [IGuideDataEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedataevent) interface and wait for the [IGuideDataEvent::ServiceChanged](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedataevent-servicechanged) event to be fired.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGuideData Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedata)