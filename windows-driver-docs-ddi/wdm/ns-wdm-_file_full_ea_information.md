# _FILE_FULL_EA_INFORMATION structure

## Description

The **FILE_FULL_EA_INFORMATION** structure provides extended attribute (EA) information.

## Members

### `NextEntryOffset`

The offset of the next **FILE_FULL_EA_INFORMATION**-type entry. This member is zero if no other entries follow this one.

### `Flags`

Can be zero or can be set with FILE_NEED_EA, indicating that the file to which the EA belongs cannot be interpreted without understanding the associated extended attributes.

### `EaNameLength`

The length in bytes of the **EaName** array. This value does not include a null-terminator to **EaName**.

### `EaValueLength`

The length in bytes of each EA value in the array.

### `EaName`

An array of characters naming the EA for this entry.

## Remarks

This structure is longword-aligned. If a set of **FILE_FULL_EA_INFORMATION** entries is buffered, **NextEntryOffset** value in each entry, except the last, falls on a longword boundary.

The value(s) associated with each entry follows the **EaName** array. That is, an EA's values are located at **EaName** + (**EaNameLength** + 1).

## See also

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)