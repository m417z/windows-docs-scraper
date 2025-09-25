# IFaxConfiguration::get_ArchiveSizeHigh

## Description

The value that specifies the high-order 32-bit value (in bytes) for the size of the fax message archive.

This property is read-only.

## Parameters

## Remarks

Because the archive may exceed 4 gigabytes (GB) in size, the archive size is described using two long values. [ArchiveSizeLow](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nf-faxcomex-ifaxconfiguration-get_archivesizelow) is the low 32-bit value of the archive size. **ArchiveSizeHigh** is the high 32-bit value of the archive size. The size of the archive is: **ArchiveSizeLow** + 4 GB * **ArchiveSizeHigh**.

If both the [ArchiveSizeLow](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nf-faxcomex-ifaxconfiguration-get_archivesizelow) and **ArchiveSizeHigh** properties have the value 0xffffffff, they specify an invalid archive size, and you should ignore both property values.

To read this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[IFaxConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxconfiguration)