# IFaxIncomingArchive::put_LowQuotaWaterMark

## Description

The **LowQuotaWaterMark** property is a value that specifies the lower warning threshold for the archive of inbound fax messages, in megabytes. If the fax service has issued a warning in the event log, the service does not issue additional warnings until the size of the inbound archive drops below this value.

This property is read/write.

## Parameters

## Remarks

**Note** This property is not supported in Windows Vista, Windows Server 2008, and later versions of Windows. To access this property in Windows Vista, Windows Server 2008, and later versions of Windows, get the [IFaxConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxconfiguration) interface from the [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) interface, and then call the [IFaxConfiguration::put_LowQuotaWaterMark](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-lowquotawatermark-vb) or [IFaxConfiguration::get_LowQuotaWaterMark](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-lowquotawatermark-vb) method.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[IFaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingarchive)