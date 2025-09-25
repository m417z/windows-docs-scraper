# IBDA_GuideDataDeliveryService::GetServices

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a list of services that are available on the the media transform device (MTD).

## Parameters

### `pulcbBufferLen` [in, out]

On input, specifies the size of the *pbBuffer* array, in bytes. On output, receives the size of the data that was written to the *pbBuffer* array.

### `pbBuffer` [out]

Pointer to a byte array that receives a list of service identifiers. A service identifier is a 64-bit value. To translate a service identifier into a tune request, call [IBDA_GuideDataDeliveryService::GetTuneXmlFromServiceIdx](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_guidedatadeliveryservice-gettunexmlfromserviceidx).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_GuideDataDeliveryService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_guidedatadeliveryservice)