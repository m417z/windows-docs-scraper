# IFaxOutgoingArchive::put_ArchiveFolder

## Description

The **IFaxOutgoingArchive::get_ArchiveFolder** property is a null-terminated string that specifies the folder location on the fax server for archived outbound faxes.

This property is read/write.

## Parameters

## Remarks

**Note** This property is not supported in Windows Vista, Windows Server 2008, and later versions of Windows. To access this property in Windows Vista, Windows Server 2008, and later versions of Windows, get the [IFaxConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxconfiguration) interface from the [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) interface, and then call the [IFaxConfiguration::put_ArchiveLocation](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-archivelocation-vb) or [IFaxConfiguration::get_ArchiveLocation](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-archivelocation-vb) method.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingarchive)

[IFaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-outgoing-archive)