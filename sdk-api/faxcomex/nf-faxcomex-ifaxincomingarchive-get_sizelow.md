# IFaxIncomingArchive::get_SizeLow

## Description

The **SizeLow** property is a value that specifies the low 32-bit value (in bytes) for the size of the archive of inbound fax messages.

This property is read-only.

## Parameters

## Remarks

**Note** This property is not supported in Windows Vista, Windows Server 2008, and later versions of Windows.

Because the archive may exceed 4 GB in size, the archive's size is described using two long values. SizeLow is the low 32-bit value of the archive size. SizeHigh is the high 32-bit value of the archive size. The size of the archive is: SizeLow + 4 GB * SizeHigh.

If both the **SizeLow** and [SizeHigh](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingarchive-sizehigh-vb) properties have the value 0xffffffff, they specify an invalid archive size, and you should ignore both property values.

To read this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingarchive)

[IFaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-incoming-archive)