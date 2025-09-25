# IFaxOutgoingArchive::get_SizeLow

## Description

The **IFaxOutgoingArchive::get_SizeLow** property is a value that specifies the low 32-bit value (in bytes) for the size of the archive of outgoing fax messages.

This property is read-only.

## Parameters

## Remarks

**Note** This property is not supported in Windows Vista, Windows Server 2008, and later versions of Windows. To access this property in Windows Vista, Windows Server 2008, and later versions of Windows, get the [IFaxConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxconfiguration) interface from the [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) interface, and then call the [IFaxConfiguration::get_ArchiveSizeLow](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nf-faxcomex-ifaxconfiguration-get_archivesizelow) method.

Because the archive may exceed 4 gigabytes (GB) in size, the archive size is described using two long values. **SizeLow** is the low 32-bit value of the archive size. [SizeHigh](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingarchive-sizehigh-vb) is the high 32-bit value of the archive size. The size of the archive is: **SizeLow** + 4 GB * **SizeHigh**. If both the **SizeLow** and **SizeHigh** properties have the value 0xffffffff, they specify an invalid archive size, and you should ignore both property values.

To read this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingarchive)

[IFaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-outgoing-archive)