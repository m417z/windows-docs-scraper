# IUPnPServiceEnumProperty::SetServiceEnumProperty

## Description

The **SetServiceEnumProperty** method is used to indicate opt-in to the delayed Service Control Protocol Description (SCPD) download and event subscription for the [IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice) objects enumerated from the [IUPnPServices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservices) object.

## Parameters

### `dwMask`

Specifies a bit-wise flag to indicate an opt-in to the delayed SCPD download and even subscription. Possible values include:

| Flag | Value |
| --- | --- |
| UPNP_SERVICE_DELAY_SCPD_AND_SUBSCRIPTION | 0x1 |

## Return value

Returns **S_OK** on success. Otherwise, this method returns **E_FAIL**.

## See also

[IUPnPServiceAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceasync)

[IUPnPServiceEnumProperty](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpserviceenumproperty)