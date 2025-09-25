# IFaxServer::get_APIVersion

## Description

The **IFaxServer::get_APIVersion** property is a value that indicates the version of the fax server API.

This property is read-only.

## Parameters

## Remarks

In general, each new version of the fax server API is fully compatible with previous API versions. When connecting to a fax server using the Component Object Model (COM) objects, the API version of the fax server is not required because the COM layer performs the conversions and mapping to transparently support the fax API version of the server. However, if you want to detect the version of the fax server you are connected to, you can use the **IFaxServer::get_APIVersion** property.

## See also

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-retrieving-server-properties)