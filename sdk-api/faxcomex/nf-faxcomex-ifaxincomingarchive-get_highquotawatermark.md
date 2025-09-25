# IFaxIncomingArchive::get_HighQuotaWaterMark

## Description

The **HighQuotaWaterMark** property is a value that specifies the upper warning threshold for the size of the archive of inbound fax messages, in megabytes. If the size of the archive exceeds this value, and the [SizeQuotaWarning](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingarchive-sizequotawarning-vb) property is equal to **TRUE**, the fax service issues a warning in the event log.

This property is read/write.

## Parameters

## Remarks

**Note** This property is not supported in Windows Vista, Windows Server 2008, and later versions of Windows. To access this property in Windows Vista, Windows Server 2008, and later versions of Windows, get the [IFaxConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxconfiguration) interface from the [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) interface, and then call the [IFaxConfiguration::put_HighQuotaWaterMark](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-highquotawatermark-vb) or [IFaxConfiguration::get_HighQuotaWaterMark](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-highquotawatermark-vb) method.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingarchive)

[IFaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-incoming-archive)