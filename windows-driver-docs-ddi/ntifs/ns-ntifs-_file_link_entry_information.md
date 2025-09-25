# _FILE_LINK_ENTRY_INFORMATION structure

## Description

The **FILE_LINK_ENTRY_INFORMATION** structure describes a single NTFS hard link to an existing file.

## Members

### `NextEntryOffset`

The offset, in bytes, to the next **FILE_LINK_ENTRY_INFORMATION** structure, or 0 if the current structure is the last **FILE_LINK_ENTRY_INFORMATION** structure.

### `ParentFileId`

The ID of the parent directory of the link.

### `FileNameLength`

The length, in characters, of the **FileName** for the link.

### `FileName`

The name of the link.

## See also

[FILE_LINKS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_links_information)