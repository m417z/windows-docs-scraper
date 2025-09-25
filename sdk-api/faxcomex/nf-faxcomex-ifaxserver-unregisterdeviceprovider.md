# IFaxServer::UnregisterDeviceProvider

## Description

The **IFaxServer::UnregisterDeviceProvider** method unregisters (removes the registration of) an existing device provider. Unregistration will take place only after the fax server is restarted.

## Parameters

### `bstrUniqueName`

Type: **BSTR**

Required. Specifies the unique name that identifies the FSP that is unregistering.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Only an administrator can unregister a fax service provider.

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver)