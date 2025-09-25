# IFaxIncomingArchive::get_SizeQuotaWarning

## Description

The **SizeQuotaWarning** property is a Boolean value that indicates whether the fax service issues a warning in the event log when the size of the inbound archive exceeds the limit defined by the [HighQuotaWaterMark](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingarchive-highquotawatermark-vb) property.

This property is read/write.

## Parameters

## Remarks

**Note** This property is not supported in Windows Vista, Windows Server 2008, and later versions of Windows. To access this property in Windows Vista, Windows Server 2008, and later versions of Windows, get the [IFaxConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxconfiguration) interface from the [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) interface, and then call the [IFaxConfiguration::put_SizeQuotaWarning](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-sizequotawarning-vb) or [IFaxConfiguration::get_SizeQuotaWarning](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-sizequotawarning-vb) method.

If this property is equal to **TRUE**, the fax service will issue a warning when the number of fax messages exceeds the threshold. If this property is equal to **FALSE**, the fax service does not issue a warning.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingarchive)

[IFaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-incoming-archive)