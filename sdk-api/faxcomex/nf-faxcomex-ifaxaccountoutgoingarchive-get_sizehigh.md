# IFaxAccountOutgoingArchive::get_SizeHigh

## Description

Specifies the high-order 32-bit value of the size (in bytes) of the archive of outbound fax messages for a particular fax account.

This property is read-only.

## Parameters

## Remarks

Because the archive size can exceed 4 GB in size, its size is described as a 64-bit integer whose value is returned as two 32-bit integer values. SizeLow returns the low-order 32-bit value of the archive size. SizeHigh returns the high-order 32-bit value of the archive size. The 64-bit value of the archive size can be computed as: Size64 = (SizeHigh << 32) + SizeLow.

If both the [SizeLow](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountoutgoingarchive-sizelow-vb) and **SizeHigh** properties have the value 0xffffffff, they specify an invalid archive size, and you should ignore both property values.

The property is read-only.

To read this property, a user must have the [far2QUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access right.

## See also

[FaxAccountOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountoutgoingarchive)

[IFaxAccountOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountoutgoingarchive)