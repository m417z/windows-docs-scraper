# IFaxIncomingArchive::put_ArchiveFolder

## Description

The **ArchiveFolder** property is a null-terminated string that specifies the folder location on the fax server for archived inbound faxes.

This property is read/write.

## Parameters

## Remarks

**Note** This property is not supported in Windows Vista, Windows Server 2008, and later versions of Windows. To access this property in Windows Vista, Windows Server 2008, and later versions of Windows, get the [IFaxConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxconfiguration) interface from the [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) interface, and then call the [IFaxConfiguration::put_ArchiveLocation](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-archivelocation-vb) or [IFaxConfiguration::get_ArchiveLocation](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-archivelocation-vb) method.

## See also

[FaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingarchive)

[IFaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-incoming-archive)