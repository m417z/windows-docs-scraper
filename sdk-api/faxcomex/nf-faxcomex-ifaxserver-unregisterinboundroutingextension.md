## Description

The **IFaxServer::UnregisterInboundRoutingExtension** method unregisters an existing inbound routing extension. Unregistration will take place only after the fax server is restarted.

## Parameters

### `bstrExtensionUniqueName`

Type: **BSTR**

String value that specifies the internal name of the fax routing extension DLL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only an administrator can unregister a routing extension. Also, this method works only on the local fax server.

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver)