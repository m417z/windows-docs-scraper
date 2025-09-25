# IFaxOutgoingArchive::Save

## Description

The **IFaxOutgoingArchive::Save** method saves the [FaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingarchive) object data.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** In Windows Vista, Windows Server 2008, and later versions of Windows, this method is not supported and returns an error.

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) and **farQUERY_CONFIG** access rights.

## See also

[FaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingarchive)

[IFaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-outgoing-archive)