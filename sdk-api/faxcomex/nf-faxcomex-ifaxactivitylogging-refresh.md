# IFaxActivityLogging::Refresh

## Description

The **IFaxActivityLogging::Refresh** method refreshes [FaxActivityLogging](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxactivitylogging) object information from the fax server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the **IFaxActivityLogging::Refresh** method is called, any configuration changes made after the last [IFaxActivityLogging::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxactivitylogging-save-vb) method call are lost.

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxActivityLogging](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxactivitylogging)

[IFaxActivityLogging](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxactivitylogging)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-logging-options)