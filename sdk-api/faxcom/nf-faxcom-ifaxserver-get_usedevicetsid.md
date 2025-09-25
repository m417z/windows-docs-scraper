# IFaxServer::get_UseDeviceTsid

## Description

Sets or retrieves the **UseDeviceTsid** property for a [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client) object. The **UseDeviceTsid** property is a Boolean value that indicates whether the fax server uses the device's transmitting station identifier (TSID) instead of a user-specified TSID.

This property is read/write.

## Parameters

## Remarks

To ensure that the TSID for a port is associated with outbound faxes, set the **UseDeviceTsid** property equal to **TRUE**. This overrides the TSID a user can optionally specify for an outbound fax by setting the [Tsid](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-tsid-vb) property.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver)

[Tsid](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxdoc-get-tsid-vb)