# IBDA_GuideDataDeliveryService::GetGuideDataType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the format UUID for the data that is retrieved on this service.

## Parameters

### `pguidDataType` [out]

Receives either a UUID that identifies the format of the guide data or the network GUID that the tuner supports for in-band guide purposes. Possible values include the following.

| Value | Meaning |
| --- | --- |
| **CLSID_PBDA_GDDS_DATA_TYPE** | Protected Broadcast Driver Architecture Service Information (PBDA-SI) format. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_GuideDataDeliveryService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_guidedatadeliveryservice)