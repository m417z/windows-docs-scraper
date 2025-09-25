# IGuideData::GetServices

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetServices** method retrieves a collection of tune requests representing all the services available in the tuning space.

## Parameters

### `ppEnumTuneRequests` [out]

Pointer to a variable that receives an [IEnumTuneRequests](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-ienumtunerequests) interface pointer. Use this interface to enumerate the properties. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is used to enumerate all services listed in the service descriptor table. Each tune request in the returned collection contains locator data for the service. To get more information about a service, pass the [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) pointer to the [IGuideData::GetServiceProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedata-getserviceproperties) method.

The method fails if the TIF has not received the service information from the PSI tables in the transport stream. The client should implement the [IGuideDataEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedataevent) interface and wait for the [IGuideDataEvent::ServiceChanged](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedataevent-servicechanged) event to be fired.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGuideData Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedata)