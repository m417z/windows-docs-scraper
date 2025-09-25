# IFaxOutgoingArchive::Refresh

## Description

The **IFaxOutgoingArchive::Refresh** method refreshes [FaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingarchive) object information from the fax server. When the **IFaxOutgoingArchive::Refresh** method is called, any configuration changes made after the last [IFaxOutgoingArchive::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingarchive-save-vb) method call are lost.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** In Windows Vista, Windows Server 2008, and later versions of Windows, this method is not supported and returns an error.

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingarchive)

[IFaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-outgoing-archive)