# IBDA_GuideDataDeliveryService::GetGuideData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the next set of guide data that is available.

## Parameters

### `pulcbBufferLen` [in, out]

Size of the *pbBuffer* array, in bytes.

### `pbBuffer` [out]

Pointer to a byte array that receives the guide data.

### `pulGuideDataPercentageProgress` [out]

Receives a value from 0 to 100. The value specifies the percent of guide data that was transferred from the media transform device (MTD) to the media sink device (MSD) since the last call to [IBDA_GuideDataDeliveryService::RequestGuideDataUpdate](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_guidedatadeliveryservice-requestguidedataupdate).

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return value | Description |
| --- | --- |
| S_OK | Success. |
| BDA_E_NO_MORE_DATA | The MTD has no more data to return. |

## See also

[IBDA_GuideDataDeliveryService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_guidedatadeliveryservice)