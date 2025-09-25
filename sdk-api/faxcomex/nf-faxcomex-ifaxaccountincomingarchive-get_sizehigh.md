# IFaxAccountIncomingArchive::get_SizeHigh

## Description

Specifies the high 32-bit value (in bytes) for the size of the archive of inbound fax messages for a particular fax account.

This property is read-only.

## Parameters

## Remarks

Because the archive may exceed 4 GB in size, its size is described using two long values. SizeLow is the low 32-bit value of the archive size. SizeHigh is the high 32-bit value of the archive size. The size of the archive is: SizeLow + 4 GB * SizeHigh.

If both the [SizeLow](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-sizelow-vb) and **SizeHigh** properties have the value 0xffffffff, they specify an invalid archive size, and you should ignore both property values.

The property is read-only.

To read this property, a user must have the [far2QUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access right.

## See also

[FaxAccountIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive)

[IFaxAccountIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountincomingarchive)