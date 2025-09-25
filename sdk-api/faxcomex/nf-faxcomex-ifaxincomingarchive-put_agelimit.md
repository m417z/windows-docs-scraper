# IFaxIncomingArchive::put_AgeLimit

## Description

The **AgeLimit** property is a value that indicates the number of days that the fax service retains fax messages in the archive of inbound faxes. The fax service deletes messages from the inbound archive when they exceed the age limit. If the value of this property is zero, the fax service does not enforce an age limit.

This property is read/write.

## Parameters

## Remarks

**Note** This property is not supported in Windows Vista, Windows Server 2008, and later versions of Windows. To access this property in Windows Vista, Windows Server 2008, and later versions of Windows, get the [IFaxConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxconfiguration) interface from the [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) interface, and then call the [IFaxConfiguration::put_ArchiveAgeLimit](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-archiveagelimit-vb) or [IFaxConfiguration::get_ArchiveAgeLimit](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-archiveagelimit-vb) method.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingarchive)

[IFaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-incoming-archive)