# IFaxEventLogging::Refresh

## Description

The **IFaxEventLogging::Refresh** method refreshes [IFaxEventLogging](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxeventlogging) interface information from the fax server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the [FaxEventLogging](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxeventlogging) method is called, any configuration changes made after the last [IFaxEventLogging::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxeventlogging-save-vb) method call are lost.

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxEventLogging](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxeventlogging)

[IFaxEventLogging](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxeventlogging)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-logging-options)