# IBDA_GuideDataDeliveryService::GetServiceInfoFromTuneXml

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets service information from an XML tune request.

## Parameters

### `bstrTuneXml` [in]

The XML tune request. For more information, see [IBDA_GuideDataDeliveryService::GetTuneXmlFromServiceIdx](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_guidedatadeliveryservice-gettunexmlfromserviceidx).

### `pbstrServiceDescription` [out]

Receives an XML string that contains information about the service. The caller must release the string by calling **SysFreeString**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_GuideDataDeliveryService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_guidedatadeliveryservice)