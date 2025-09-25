# _FILE_GET_EA_INFORMATION structure

## Description

The FILE_GET_EA_INFORMATION structure is used to query for extended-attribute (EA) information.

## Members

### `NextEntryOffset`

Offset, in bytes, of the next FILE_GET_EA_INFORMATION-typed entry. This member is zero if no other entries follow this one.

### `EaNameLength`

Length, in bytes, of the **EaName** array. This value does not include a NULL terminator.

### `EaName`

Specifies the first character of the name of the extended attribute to be queried. This is followed in memory by the remainder of the string.

## Remarks

The FILE_GET_EA_INFORMATION structure is used to query for extended-attribute (EA) information. The EA information is returned in a [FILE_FULL_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)-structured buffer.

This structure must be aligned on a LONG (4-byte) boundary.

## See also

[FILE_FULL_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)

[IRP_MJ_QUERY_EA](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-ea)

[IoCheckEaBufferValidity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckeabuffervalidity)