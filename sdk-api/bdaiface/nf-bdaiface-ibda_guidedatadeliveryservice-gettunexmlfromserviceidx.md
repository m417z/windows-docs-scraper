# IBDA_GuideDataDeliveryService::GetTuneXmlFromServiceIdx

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Converts a service identifier into an XML tune request.

A service identifier (*ServiceIdx*) is a 64-bit identifier, used in the PBDA EIT guide delivery format. An XML tune request (*TuneXml*) is an XML string that can be used to tune to the service.

## Parameters

### `ul64ServiceIdx` [in]

Identifier for the service.

### `pbstrTuneXml` [out]

Receives the XML tune request. The caller must release the string by calling **SysFreeString**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_GuideDataDeliveryService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_guidedatadeliveryservice)